--
-- premake.lua
--
-- Premake build script
--
-- Copyright (c) 2004-2008, Applied Informatics Software Engineering GmbH.
-- and Contributors.
--
-- Permission is hereby granted, free of charge, to any person or organization
-- obtaining a copy of the software and accompanying documentation covered by
-- this license (the "Software") to use, reproduce, display, distribute,
-- execute, and transmit the Software, and to prepare derivative works of the
-- Software, and to permit third-parties to whom the Software is furnished to
-- do so, all subject to the following:
--
-- The copyright notices in the Software and this entire statement, including
-- the above license grant, this restriction and the following disclaimer,
-- must be included in all copies of the Software, in whole or in part, and
-- all derivative works of the Software, unless such copies or derivative
-- works are solely in the form of machine-executable object code generated by
-- a source language processor.
--
-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
-- IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-- FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
-- SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
-- FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
-- ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
-- DEALINGS IN THE SOFTWARE.
--

if (options["target"] == "vs6") then
    error("Visual Studio 6 is no longer supported; please upgrade to Visual Studio 2003, 2005, 2008 or their Express versions.")
elseif (options["target"] == "vs2003") then
    project.name = "Foundation".."_vs71"
elseif (options["target"] == "vs2005") then
    project.name = "Foundation".."_vs80"
elseif (options["target"] == "vs2008") then
    project.name = "Foundation".."_vs90"
else 
    project.name = "Foundation"
end

-- Define the build configurations. You can also use the flags
-- `--enable-shared-only` and `--enable-static-only` if you want to
-- call these packages from within your own Premake-enabled project.

if (options["enable-shared-only"]) then
    project.configs = { "debug_shared", "release_shared"}
elseif (options["enable-static-only"]) then
    project.configs = { "debug_static", "release_static"}
else
    project.configs = { "debug_shared", "release_shared", "debug_static", "release_static"}
end


-- Project options

addoption("with-samples",    		"Builds the sample applications and DrawStuff library")
addoption("with-testsuite",    	    "Builds the unit test application")
addoption("enable-static-only",	    "Only create static library (.lib) project configurations")
addoption("enable-shared-only",	    "Only create dynamic library (.dll) project configurations")

-- Output is placed in a directory named for the target toolset.
-- project.path = options["target"]
project.path = "."

-- Set the output directories

project.config["debug_shared"].bindir   = "../bin"
project.config["debug_shared"].libdir   = "../lib"

project.config["release_shared"].bindir = "../bin"
project.config["release_shared"].libdir = "../lib"

project.config["debug_static"].libdir   = "../lib"
project.config["release_static"].libdir = "../lib"

-- Build packages

if (options["with-samples"]) then
    dopackage("samples.lua")
end

if (options["with-testsuite"]) then
    dopackage("testsuite.lua")
end

dopackage("poco.lua")


-- Remove all intermediate files

function doclean(cmd, arg)
    docommand(cmd, arg)
    os.rmdir("custom")
    os.rmdir("../lib/debug_shared")
    os.rmdir("../lib/debug_static")
    os.rmdir("../lib/release_shared")
    os.rmdir("../lib/release_static")
    os.rmdir("gnu/obj")
    os.rmdir("vs2003/obj")
    os.rmdir("vs2005/obj")
    os.rmdir("vs2008/obj")
end


-- Generate all toolsets in one go

function domakeall(cmd, arg)
--    os.execute("premake --usetargetpath --with-samples --with-testsuite --clean --target vs6")
    os.execute("premake --usetargetpath --with-samples --with-testsuite --clean --target vs2003")
    os.execute("premake --usetargetpath --with-samples --with-testsuite --clean --target vs2005")
    os.execute("premake --usetargetpath --with-samples --with-testsuite --clean --target vs2008")
    os.execute("premake --usetargetpath --with-samples --with-testsuite --clean --target gnu")
    os.execute("premake --usetargetpath --with-samples --with-testsuite --clean --target cb-gcc")
end
