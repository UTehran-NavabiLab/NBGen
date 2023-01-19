from liberty.parser import parse_liberty
import re

class Technology_file:
    def __init__(self, technology_file_dir) -> None:
        library = parse_liberty(open(technology_file_dir).read())
        self.cells = library.get_groups('cell')
        self.list_of_buf = list()
        self.list_of_buf_input = list()
        self.list_of_buf_output = list()
        self.list_of_inv = list()
        self.list_of_inv_input = list()
        self.list_of_inv_output = list()
        self.list_of_dff = list()
        self.dict_of_dff = dict()
        self.list_of_clk = list()
        self.list_of_rst = list()
        self.list_of_set = list()
        self.list_of_dff_Q = list()
        self.list_of_dff_D = list()
        self.dff_info()
        self.list_of_inv_buf()



    def dff_info(self):
        for cell in self.cells:
            if len(cell.get_groups('ff')) == 1: # if is sequential cell
                self.dict_of_dff.update({cell.args[0]: {
                    "output" : self.find_dff_Q_signal(cell),
                    "next_state": self.find_dff_D_signal(cell),
                    "clocked_on": self.find_dff_clk(cell),
                    "preset": self.find_set_signal(cell),
                    "clear": self.find_rst_signal(cell)
                }})
                self.list_of_dff.append(cell.args[0]) # add cell name to dff list 
                self.find_set_signal(cell)
                self.find_rst_signal(cell)
                self.find_dff_clk(cell)
                self.find_dff_D_signal(cell)
                self.find_dff_Q_signal(cell)

    def find_dff_clk(self,cell):
        clk_list = list()
        for pin in cell.get_groups('pin'):
            if (pin["clock"] == "true"):
                clk_list.append(pin.args[0])
                
        self.list_of_clk.append(clk_list)
        if (len(clk_list) > 1):
            return clk_list
        else:
            return clk_list[0]

    def find_set_signal(self,cell):
        FF = cell.get_groups('ff')
        self.list_of_set.append( re.sub(r'[\W_]', '', str(FF[0]["preset"])))
        return ( re.sub(r'[\W_]', '', str(FF[0]["preset"])))

    def find_rst_signal(self,cell):
        FF = cell.get_groups('ff')
        self.list_of_rst.append( re.sub(r'[\W_]', '', str(FF[0]["clear"])))
        return ( re.sub(r'[\W_]', '', str(FF[0]["clear"])))

    def find_dff_Q_signal(self, cell):
        Q_list = list()
        for pin in cell.get_groups('pin'):
            if pin["direction"] == "output":
                Q_list.append(pin.args[0])

        self.list_of_dff_Q.append(Q_list)
        return Q_list

    def find_dff_D_signal(self, cell):
        FF = cell.get_groups('ff')
        self.list_of_dff_D.append(re.sub(r'[\W_]', '', str(FF[0]["next_state"])))
        return (re.sub(r'[\W_]', '', str(FF[0]["next_state"])))

    def list_of_inv_buf(self):
        for cell in self.cells:
            if len(cell.get_groups('pin')) == 2:
                i =0
                for pin in cell.get_groups('pin'):
                    if pin["direction"] == "output":
                        if str(pin["function"]).find('!') > -1 or str(pin["function"]).find('\'')>-1:
                            self.list_of_inv.append(cell.args[0])
                            self.list_of_inv_output.append(pin.args[0])
                            if i ==0:
                                self.list_of_inv_input.append(cell.get_groups('pin')[1].args[0])
                            else:
                                self.list_of_inv_input.append(cell.get_groups('pin')[0].args[0])
                        else:
                            self.list_of_buf.append(cell.args[0])
                            self.list_of_buf_output.append(pin.args[0])
                            if i ==0:
                                self.list_of_buf_input.append(cell.get_groups('pin')[1].args[0])
                            else:
                                self.list_of_buf_input.append(cell.get_groups('pin')[0].args[0])
                    i = i+1






# directory = "/Library/Frameworks/Python.framework/Versions/3.10/lib/python3.10/site-packages/utdate/lib/NangateOpenCellLibrary_typical.lib"
# tech = Technology_file(directory)



