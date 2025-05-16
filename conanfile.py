from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps
from conan.tools.files import copy, rmdir
import os

class CryptoGuardConan(ConanFile):
    name = "books_db"
    version = "0.0.1"
    settings = "os", "compiler", "build_type", "arch"
    
    def requirements(self):
        self.tool_requires("cmake/3.31.6")

        self.requires("benchmark/1.9.1")
        self.requires("abseil/20250127.0")
        self.requires("boost/1.87.0")
        # self.requires("openssl/3.4.1")
        # self.requires("sqlite3/3.49.1")
        pass
    
    def layout(self):
        self.folders.source = "."
        self.folders.build = "build"
        self.folders.generators = "build/generators"
    
    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        
        tc = CMakeToolchain(self)
        tc.generate()
    
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
