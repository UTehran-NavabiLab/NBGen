from utdate.src.technology_reader import Technology_file

# @def: 
#   remove_DFFport ; find and remove . port from DFF
#     @input   ; string of a page
def remove_DFFport(temp_page, technology_parameter):

    page2line = temp_page.splitlines()

    for indx, line in enumerate(page2line):
        # find DFF_PP
        dff_detected = False
        for dff_name, dff_ports in technology_parameter.dict_of_dff.items():
            # if (line.strip().find(dff_name) > -1) and (line.strip().find("(") > -1):
            if ((line.strip().find(dff_name) > -1) and (not(dff_detected))):
                print(dff_name)
                print(" ", line)
                for indx_2, line_2 in enumerate(page2line[indx:]):
                    # find ");" that occures after 
                    if line_2.strip().find(");") > -1:
                        for indx_3, line_3 in enumerate(page2line[indx: indx + indx_2]):
                            if line_3.strip().find(f'.{dff_ports["clocked_on"]}(') > -1:
                                print(" ", page2line[indx + indx_3])
                                dff_detected = True
                                page2line[indx + indx_3] = ""
                        break

    # create new page
    return "\n".join(page2line)

technology_parameter = Technology_file("/Users/ebinouri/Documents/UNi/NBGen/pypi_package/test/reza_Puneh/tech/mycells_yosys.lib")
with open("/Users/ebinouri/Documents/UNi/NBGen/pypi_package/test/reza_Puneh/synthesis/synth_premap.v", "r") as f:
    file = remove_DFFport(f.read(), technology_parameter)
    # print(file)