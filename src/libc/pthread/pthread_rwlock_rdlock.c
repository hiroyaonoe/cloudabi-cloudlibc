// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distrbuted under a 2-clause BSD license.
// See the LICENSE file for details.

#include <common/pthread.h>
#include <common/syscalls.h>

#include <errno.h>
#include <pthread.h>

int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock) __no_lock_analysis {
  // Attempt to acquire the lock in userspace.
  for (int i = 0; i < LOCK_RETRY_COUNT; ++i) {
    int error = pthread_rwlock_tryrdlock(rwlock);
    if (error != EBUSY)
      return error;
  }

  // Call into the kernel to acquire a read lock.
  cloudabi_subscription_t subscription = {
      .type = CLOUDABI_EVENTTYPE_LOCK_RDLOCK,
      .lock.lock = &rwlock->__state,
      .lock.lock_scope = rwlock->__pshared,
  };
  size_t triggered;
  cloudabi_event_t event;
  cloudabi_errno_t error =
      cloudabi_sys_poll(&subscription, 1, &event, 1, &triggered);
  if (error != 0)
    __pthread_terminate(error, "Failed to acquire read lock");
  if (event.error != 0)
    __pthread_terminate(event.error, "Failed to acquire read lock");

  // Lock acquired successfully.
  ++__pthread_rdlocks;
  return 0;
}
