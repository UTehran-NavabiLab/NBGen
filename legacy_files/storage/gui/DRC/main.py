from pathlib import Path
from tkinter import Tk, Frame, Canvas, Entry, Text, Button, PhotoImage, Checkbutton, BooleanVar
from tkinter import END as tk_END
from tkinter import INSERT as tk_BEGIN
import re

OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / Path("./assets")


def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)

def DRC(backend):
    DRC(backend)


class DRC(Frame):
    def __init__(self, parent, backend, controller=None, *args, **kwargs):
        Frame.__init__(self, parent, *args, **kwargs)
        self.parent = parent
        self.backend = backend
        self.testbench_name = ""
        self.instance_name = ""

        # self.geometry("800x600")
        self.configure(bg = "#FFFFFF")



        canvas = Canvas(
            self,
            bg = "#FFFFFF",
            height = 600,
            width = 550,
            bd = 0,
            highlightthickness = 0,
            relief = "ridge"
        )

        canvas.place(x = 0, y = 0)
        canvas.create_rectangle(
            0,
            0.0,
            550.0,
            600.0,
            fill="#FFFFFF",
            outline="")

        canvas.create_rectangle(
            0.0,
            0.0,
            550.0,
            8.0,
            fill="#EE5959",
            outline="")

        # Images: upper ribbon, Logo -----------------------------
        canvas.image_image_1 = PhotoImage(
            file=relative_to_assets("image_1.png"))
        image_1 = canvas.create_image(
            68.0,
            35.0,
            image=canvas.image_image_1
        )

        canvas.image_image_2 = PhotoImage(
            file=relative_to_assets("image_2.png"))
        image_2 = canvas.create_image(
            490.0,
            68.0,
            image=canvas.image_image_2
        )

        canvas.create_text(
            11.0,
            22.0,
            anchor="nw",
            text="DRC",
            fill="#FFFFFF",
            font=("Inter", 21 * -1)
        )
        # Buttons: design rule check --------------------
        self.design_rule_check_img = PhotoImage(
            file=relative_to_assets("design_rule_check.png"))
        self.design_rule_check_fail_img = PhotoImage(
            file=relative_to_assets("fail_drc.png"))
        self.design_rule_check_success_img = PhotoImage(
            file=relative_to_assets("success_drc.png"))
        # TODO: #DONE
        #   add success of fail
        # self.design_rule_check_success_img = PhotoImage(
        #     file=relative_to_assets("design_rule_check_success.png"))
        # self.design_rule_check_fail_img = PhotoImage(
        #     file=relative_to_assets("design_rule_check_fail.png"))
        self.design_rule_check_btn = Button(
            self,
            image=self.design_rule_check_img,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.check_design_rules(),
            relief="flat"
        )
        self.design_rule_check_btn.place(
            x=71,
            y=533.0,
            width=200.0,
            height=37.0
        )

        #################################################
        self.scan_log_img = PhotoImage(
            file=relative_to_assets("log_enable.png"))
        self.scan_log_disable_img = PhotoImage(
            file=relative_to_assets("log_disable.png"))

        self.open_log_btn = Button(
            self,
            image=self.scan_log_disable_img,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.open_log(),
            relief="flat"
        )
        self.open_log_btn.place(
            x=281.0, #278 
            y=533.0,
            width=200.0,
            height=37.0
        )
        self.rule_check_result = Text(
            self,
            bd=0,
            bg="#D9D9D9",
            font=("Courier", 9),
            highlightthickness=0,
            width=50, #39
            height=26 #34
        )
        self.rule_check_result.place(
                x=95.0, #16
                y=126.0
            )
        self.rule_check_result.config(state="disabled")


        # Function Definition --------------------
    def check_design_rules(self):
        #print("hello")
        input_file_directory = list()
        file_names = list()
        ########## TO BE CHANGED ####
        for file_name, file_dir in self.parent.windows["file"].get_files().items():
            input_file_directory.append(file_dir)
            file_names.append(file_name)
        print(file_names)
        print(input_file_directory)
        drc_log , success = self.backend.design_rule_check(input_file_directory,"design.v")
        self.rule_check_result.config(state="normal")
        self.rule_check_result.delete(1.0, tk_END)

        tag_name = ""
        for phrase in drc_log:
            tag_name += "tt"
            if phrase.find("Type = Warning") > -1 :
                index = 16
                color = "#f08a00"
            elif phrase.find("Type = Report") > -1:
                index = 15
                color = "black"
            elif phrase.find("Type = Error") > -1:
                index = 14
                color = "#d31d00"
            elif phrase.find("Type = Success") > -1:
                index = 16
                color = "#50ac08"
            self.rule_check_result.insert(tk_END, phrase[index:])
            position = tk_END + " - " + str(len(phrase[index:])+1) + "c"
            self.rule_check_result.tag_add(tag_name,position, tk_END)
            self.rule_check_result.tag_config(tag_name, foreground=color)
        self.rule_check_result.config(state="disabled")

        self.pos_of_Drc = "1.0 + " + str(len(self.rule_check_result.get(1.0 , tk_END))) + "c"
        

        if(success):
             self.design_rule_check_btn.config(image=self.design_rule_check_success_img)
             # TO-DO: you should choose from another page
             self.parent.windows["scan"].scan_synthesis_btn.config(state="normal")
             self.parent.windows["scan"].scan_synthesis_btn.config(image=self.parent.windows["scan"].scan_synthesis_img)
           #  self.scan_synthesis_btn.config(state="normal")
           #  self.scan_synthesis_btn.config(image=self.scan_synthesis_img)
        else:
             self.design_rule_check_btn.config(image=self.design_rule_check_fail_img)

            
        pass


    # def single_scan_select(self):
    #     if (self.single_scan_var.get()):
    #         if (self.multiple_scan_var.get()):
    #             self.multiple_scan_btn.invoke()
    #         self.si_port_name_single_entry.config(state="normal")
    #         self.so_port_name_single_entry.config(state="normal")
    #     else:
    #         self.si_port_name_single_entry.config(state="disabled")
    #         self.so_port_name_single_entry.config(state="disabled")

    # def multiple_scan_select(self):
    #     if (self.multiple_scan_var.get()):
    #         if (self.single_scan_var.get()):
    #             self.single_scan_btn.invoke()
    #         self.chain_number_entry.config(state="normal")
    #         self.si_port_name_multi_entry.config(state="normal")
    #         self.so_port_name_multi_entry.config(state="normal")
    #     else:
    #         self.chain_number_entry.config(state="disabled")
    #         self.si_port_name_multi_entry.config(state="disabled")
    #         self.so_port_name_multi_entry.config(state="disabled")
        
    # def synthesize_scan(self):
    #     input_file_directory = list()
    #     file_names = list()
    #     for file_name, file_dir in self.parent.windows["file"].get_files().items():
    #         input_file_directory.append(file_dir)
    #         file_names.append(file_name)

    #     if(self.single_scan_var.get()):
    #         self.rule_check_result.config(state="normal")
    #         self.rule_check_result.delete(self.pos_of_Drc, tk_END)

    #         si = self.si_port_name_single_entry.get()
    #         so = self.so_port_name_single_entry.get()

    #         if( si == "Enter Si Port Name" or so == "Enter So Port Name"):
    #             return

    #         elif (bool(re.match('^[a-zA-Z0-9_$]*$',si))== False or bool(re.match('^[a-zA-Z0-9_$]*$',so))== False):
    #             report = " --- Port names are not valid\n"
    #             self.rule_check_result.insert(tk_END, report)
    #             position = tk_END + " - " + str(len(report)+1) + "c"
    #             self.rule_check_result.tag_add("si",position, tk_END)
    #             self.rule_check_result.tag_config("si", foreground="#d31d00")
    #             self.rule_check_result.config(state="disable")
    #             return
    #         else:
    #             print(si, so)
    #             self.backend.scan_synth([si], [so], None, file_names[0])
    #     elif(self.multiple_scan_var.get()):
    #         self.rule_check_result.config(state="normal")
    #         self.rule_check_result.delete(self.pos_of_Drc, tk_END)

    #         si = self.si_port_name_multi_entry.get()
    #         so = self.so_port_name_multi_entry.get()
    #         chains = self.chain_number_entry.get()

    #         if( si == "Enter Si Port Name" or so == "Enter So Port Name" or chains == "No. of cells in chain"):
    #             return
    #         else:
    #             si_list  = [x.strip() for x in si.split(',')]
    #             so_list  = [x.strip() for x in so.split(',')]
    #             chain_list = [x.strip() for x in chains.split(',')]
    #             print(chain_list)
    #             for x in si_list:
    #                 if(bool(re.match('^[a-zA-Z0-9_$]*$',x))== False):
    #                     report = " --- Port names are not valid\n"
    #                     self.rule_check_result.insert(tk_END, report)
    #                     position = tk_END + " - " + str(len(report)+1) + "c"
    #                     self.rule_check_result.tag_add("si",position, tk_END)
    #                     self.rule_check_result.tag_config("si", foreground="#d31d00")
    #                     self.rule_check_result.config(state="disable")
    #                     return
    #             for x in so_list:
    #                 if(bool(re.match('^[a-zA-Z0-9_$]*$',x))== False):
    #                     report = " --- Port names are not valid\n"
    #                     self.rule_check_result.insert(tk_END, report)
    #                     position = tk_END + " - " + str(len(report)+1) + "c"
    #                     self.rule_check_result.tag_add("cg",position, tk_END)
    #                     self.rule_check_result.tag_config("cg", foreground="#d31d00")
    #                     self.rule_check_result.config(state="disable")
    #                     return
    #             for i in range(len(chain_list)):
    #                 if(bool(re.match('^[0-9]*$',chain_list[i]))== False):
    #                     report = " --- Chain numbers are not valid\n"
    #                     self.rule_check_result.insert(tk_END, report)
    #                     position = tk_END + " - " + str(len(report)+1) + "c"
    #                     self.rule_check_result.tag_add("bs",position, tk_END)
    #                     self.rule_check_result.tag_config("bs", foreground="#d31d00")
    #                     self.rule_check_result.config(state="disable")
    #                     return
    #                 chain_list[i]=int(chain_list[i])
                    
        
    #             self.backend.scan_synth(si_list, so_list, chain_list, file_names[0])
            

    #     pass
    #     # self.backend.test_set_gen()
    #     # self.testset_btn.config(image=self.test_success_img)
    #     # self.openlog_testset_btn.config(image=self.openlog_img)

    # # call function when we click on entry box
    # def click_si_port_single_ent(*args):
    #     if (args[0].si_port_name_single_entry.get() == "Enter Si Port Name"):
    #         args[0].si_port_name_single_entry.delete(0, 'end')
    # def click_si_port_multi_ent(*args):
    #     if (args[0].si_port_name_multi_entry.get() == "Enter Si Port Name"):
    #         args[0].si_port_name_multi_entry.delete(0, 'end')
    # def click_so_port_single_ent(*args):
    #     if (args[0].so_port_name_single_entry.get() == "Enter So Port Name"):
    #         args[0].so_port_name_single_entry.delete(0, 'end')
    # def click_so_port_multi_ent(*args):
    #     if (args[0].so_port_name_multi_entry.get() == "Enter So Port Name"):
    #         args[0].so_port_name_multi_entry.delete(0, 'end')
    # def click_chain_num_ent(*args):
    #     if (args[0].chain_number_entry.get() == "No. of cells in chain"):
    #         args[0].chain_number_entry.delete(0, 'end')
    
    # # call function when we leave entry box
    # def leave_si_port_single_ent(*args):
    #     if (args[0].si_port_name_single_entry.get() == ""):
    #         args[0].si_port_name_single_entry.delete(0, 'end')
    #         args[0].si_port_name_single_entry.insert(0, 'Enter Si Port Name')
    #     args[0].focus()
    # def leave_si_port_multi_ent(*args):
    #     if (args[0].si_port_name_multi_entry.get() == ""):
    #         args[0].si_port_name_multi_entry.delete(0, 'end')
    #         args[0].si_port_name_multi_entry.insert(0, 'Enter Si Port Name')
    #     args[0].focus()
    # def leave_so_port_single_ent(*args):
    #     if (args[0].so_port_name_single_entry.get() == ""):
    #         args[0].so_port_name_single_entry.delete(0, 'end')
    #         args[0].so_port_name_single_entry.insert(0, 'Enter So Port Name')
    #     args[0].focus()
    # def leave_so_port_multi_ent(*args):
    #     if (args[0].so_port_name_multi_entry.get() == ""):
    #         args[0].so_port_name_multi_entry.delete(0, 'end')
    #         args[0].so_port_name_multi_entry.insert(0, 'Enter So Port Name')
    #     args[0].focus()
    # def leave_chain_num_ent(*args):
    #     if (args[0].chain_number_entry.get() == ""):
    #         args[0].chain_number_entry.delete(0, 'end')
    #         args[0].chain_number_entry.insert(0, 'Enter no. of chain')
    #     args[0].focus()
