workspace(name = "org_cloudabi_cloudlibc")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "org_cloudabi_bazel_third_party",
    commit = "91ca2167219c612a89334fa09ddf15fbdc5d0592",
    remote = "https://github.com/NuxiNL/bazel-third-party.git",
)

git_repository(
    name = "org_cloudabi_bazel_toolchains_cloudabi",
    commit = "a2fd1ad94eb51ff972d8db92792dbdeb0b227a24",
    remote = "https://github.com/NuxiNL/bazel-toolchains-cloudabi.git",
)

load("@org_cloudabi_bazel_third_party//:third_party.bzl", "third_party_repositories")

third_party_repositories()

load("@org_cloudabi_bazel_toolchains_cloudabi//:toolchains.bzl", "toolchains_cloudabi_dependencies")

toolchains_cloudabi_dependencies()
