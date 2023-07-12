from os import path, getcwd, chdir, mkdir
from utdate.src.utility_functions import split_page
import utdate.lib as lib


class bist_insertion:
    # get bist_configuration containing all the neccessary information about the bist and design
    def __init__(self, bist_configuration: dict) -> None:
        self.configuration = bist_configuration
        # get directory of library inside package repository
        self.bist_lib = path.join((path.join(lib.__path__[0], "test")), "bist")
        self.working_dir = getcwd()
        self.bist_dir = ""

        # check wether the "test" directory exist in working directory
        # if not create a new one
        if (path.isdir(path.join(self.working_dir, "test"))):
            self.bist_dir = path.join(self.working_dir, "test")
        else:
            test_dir = mkdir("test", self.working_dir)
            self.bist_dir = mkdir("bist", test_dir)


    def rts(self):
        RTS_template_dir = path.join(self.bist_lib, "RTS")

        # Copy unmodified files
        
        # RTS_controller ----------------
        # Read from the template
        with open(path.join(RTS_template_dir, "RTS_Controller.vhd"), "r") as rd:
            rts_cnt = rd.read()

            # replace shiftSize
            p1, p2 = split_page(rts_cnt, ["shiftSize", ":", "INTEGER", ":="])
            p2, p3 = split_page(p2, [";"])
            rts_cnt = p1 + " " + str(self.configuration["shiftSize"]) + ";" + p3

            with open(path.join(self.bist_dir, "RTS_Controller.vhd"), "w") as wr:
                wr.write(rts_cnt)

        # Virtual Tester ----------------