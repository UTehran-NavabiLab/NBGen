from subprocess import run, PIPE
from os import path, getcwd, chdir, listdir, mkdir

output_log = "/Users/ebinouri/Documents/UNi/NBGen/difference_log.txt"
base_dir2 = "/Library/Frameworks/Python.framework/Versions/3.10/lib/python3.10/site-packages/utdate"
base_dir1 = "/Users/ebinouri/Documents/UNi/NBGen/pypi_package/src/utdate"

list_of_files = list()

# name_replacement1 = [
#     "/Users/ebinouri/Documents/UNi/OpenSourceTools/fault_injection_framwork_uvm_based/testsuites/notify_mechanism__all_naming/src/fi_framework/utils/test_spec_reader.h",
# ]
# name_replacement2 = [
#     "/Users/ebinouri/Documents/UNi/OpenSourceTools/fault_injection_framwork_uvm_based/testsuites/notify_mechanism/src/fi_framework/utils/test_spec_reader.h",
# ]

def find_file_list(source_folder):
    final_log = ""
    # fetch all files
    for file_dir_name in listdir(source_folder):
        directory = path.join(source_folder, file_dir_name)
        # if directory
        if (path.isdir(directory)):
            find_file_list(directory)
        else:
            if (((file_dir_name.find(".h") > -1) and file_dir_name.find(".hpp") < 0) or (file_dir_name.find(".cpp") > -1) or ((file_dir_name.find(".py") > -1) and (file_dir_name.find(".pyc") < 0))):
                path1 = path.join(source_folder, file_dir_name)
                second = path1.rsplit(base_dir1, 1)[1][1:]
                path2 = path.join(base_dir2, second)

                if (path.isfile(path2)):
                    log = "=============="  + "\n"
                    log += "file: " + file_dir_name + "\n"
                    log += run(["diff", path1, path2], stdout=PIPE, text=True).stdout + "\n"
                    log += "=============="  + "\n"
                    
                    final_log += log

    # for i in range(len(name_replacement1)):
    #     path1 = name_replacement1[i]
    #     path2 = name_replacement2[i]
    #     log = "=============="  + "\n"
    #     log += "file: " + name_replacement1[i].rsplit("/", 1)[1] + "\n"
    #     log += run(["diff", path1, path2], stdout=PIPE, text=True).stdout + "\n"
    #     log += "=============="  + "\n"
        
    #     final_log += log

    print(final_log)
    # with open(output_log, "w") as f:
    #     f.write(final_log)


find_file_list(base_dir1)
