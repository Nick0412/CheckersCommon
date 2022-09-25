from conans import ConanFile, tools


class CheckersCommonConan(ConanFile):
    name = "CheckersCommon"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    description = "Common code and utilities for CheckersClient and CheckersServer."
    url = "https://github.com/Nick0412/CheckersCommon.git"

    def requirements(self):
        self.requires("gtest/1.12.1")

    def configure(self):
        self.generators = ["cmake"]