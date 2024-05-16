workspace(name = "org_cloudabi_cloudlibc")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "org_cloudabi_bazel_third_party",
    commit = "042d5730e484e4895e97fa6950eedc14f9c74088",
    remote = "https://github.com/hiroyaonoe/cloudabi-bazel-third-party.git",
)

git_repository(
    name = "org_cloudabi_bazel_toolchains_cloudabi",
    commit = "c7e4d6089ac01864b889568f7d56e18bf31c7684",
    remote = "https://github.com/hiroyaonoe/cloudabi-bazel-toolchains-cloudabi.git",
)

load("@org_cloudabi_bazel_third_party//:third_party.bzl", "third_party_repositories")

third_party_repositories()

load("@org_cloudabi_bazel_toolchains_cloudabi//:toolchains.bzl", "toolchains_cloudabi_dependencies")

toolchains_cloudabi_dependencies()
