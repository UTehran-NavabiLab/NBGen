
def split_page(page, sequence):
    pointer = 0
    for i in range(len(sequence)):
        pointer = page.find(sequence[i], pointer)
        
    return page[:pointer + len(sequence[-1])], page[pointer + len(sequence[-1]):]

with open(("/Users/ebinouri/Documents/UNi/NBGen/pypi_package/src/utdate/lib/bist/RTS/RTS_Controller.vhd"), "r") as rd:
    rts_cnt = rd.read()
    i = rts_cnt.find("shiftSize : INTEGER := ")
    rts_cnt.replace("shiftSize : INTEGER := ", "shiftSize : INTEGER := 120")
    p1, p2 = split_page(rts_cnt, ["shiftSize", ":", "INTEGER", ":="])
    p2, p3 = split_page(p2, [";"])
    page = p1 + " 120" + ";" + p3
    # print(p1)
    # print("88*****************892")
    # print(p2)
    # print("88*****************892")
    # print(p3)
    print(page)
