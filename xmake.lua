add_rules("mode.debug")
set_toolchains("msvc")
set_languages("c++23")

add_repositories("MrowrLib https://github.com/MrowrLib/package-repo.git")
add_repositories("ModdingFramework https://github.com/ModdingFramework/package-repo.git")

add_requires("fmt", "Memory", "Assembly", "spdlog", "uint128_t")

target("CodeInjection")
    set_kind("headeronly")
    add_headerfiles("include/(**.h)")
    add_includedirs("include", {public = true})
    add_packages("Assembly", "Memory", "uint128_t", {public = true})

target("Example")
    set_kind("binary")
    add_files("Example.cpp")
    add_deps("CodeInjection")
    add_packages("spdlog")
