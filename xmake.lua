add_rules("mode.debug")
set_toolchains("msvc")
set_languages("c++20")

add_repositories("MrowrLib https://github.com/MrowrLib/Packages.git")

add_requires("memory_util", "assembly", "uint128_t", "spdlog")

target("CodeInjection")
    set_kind("headeronly")
    add_headerfiles("include/(**.h)")
    add_includedirs("include", {public = true})
    add_packages("assembly", "memory_util", "uint128_t", {public = true})

target("Example")
    set_kind("binary")
    add_files("Example.cpp")
    add_deps("CodeInjection")
    add_packages("spdlog")
