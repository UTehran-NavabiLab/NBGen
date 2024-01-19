from pathlib import Path
from tkinter import Tk, Frame, Canvas, Entry, Text, Button, PhotoImage, Checkbutton, BooleanVar
from tkinter import END as tk_END
from tkinter import INSERT as tk_BEGIN
import re


OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / Path("./assets")


def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)

def Scan(backend):
    Scan(backend)


class Scan(Frame):
    def __init__(self, parent, backend, controller=None, *args, **kwargs):
        Frame.__init__(self, parent, *args, **kwargs)
        self.parent = parent
        self.backend = backend
        self.testbench_name = ""
        self.instance_name = ""
        self.end_of_info = 1.0

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
            text="Scan Synth.",
            fill="#FFFFFF",
            font=("Inter", 21 * -1)
        )
        
        # Buttons: scan synthesis --------------------
        self.scan_synthesis_img = PhotoImage(
            file=relative_to_assets("scan_synthesis.png"))
        self.scan_success_img = PhotoImage(
            file=relative_to_assets("scan_success.png"))
        self.scan_fail_img = PhotoImage(
            file=relative_to_assets("scan_fail.png"))
        self.scan_disable_img = PhotoImage(
            file=relative_to_assets("scan_disable.png"))
        # TODO:
        #   add success and fail if possible
        # self.test_img = PhotoImage(
        #     file=relative_to_assets("test.png"))
        # self.test_success_img = PhotoImage(
        #     file=relative_to_assets("test_success.png"))
        # self.test_fail_img = PhotoImage(
        #     file=relative_to_assets("test_fail.png"))
        self.scan_synthesis_btn = Button(
            self,
            image=self.scan_disable_img,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.synthesize_scan(),
            relief="flat"
        )
        self.scan_synthesis_btn.place(
            x=19.0, #278 
            y=515.0,
            width=240.0,
            height=37.0
        )

        self.scan_synthesis_btn.config(state="disabled")
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
            x=278.0, #278 
            y=515.0,
            width=240.0,
            height=37.0
        )
        ################################################
        # Buttons: single chain check-box --------------------
        self.checkbox_yellow_img = PhotoImage(
            file=relative_to_assets("checkbox_yellow.png"))
        self.checkbox_green_img = PhotoImage(
            file=relative_to_assets("checkbox_green.png"))

        self.single_scan_var = BooleanVar(value=False)
        self.single_scan_btn = Checkbutton(
            self, 
            command=lambda: self.single_scan_select(),
            variable=self.single_scan_var,
            onvalue=True,
            offvalue=False)

        # self.single_scan_btn = Button(
        #     self,
        #     image=self.checkbox_yellow_img,
        #     borderwidth=0,
        #     highlightthickness=0,
        #     command=lambda: self.single_scan_select(),
        #     relief="flat"
        # )
        self.single_scan_btn.place(
            x=16.0,
            y=155.0,
            width=20.0,
            height=20.0
        )

        canvas.create_text(
            47.0,
            152.0,
            anchor="nw",
            text="Single Chain Full Scan",
            fill="#000000",
            font=("Inter", 20 * -1)
        )

        # Buttons: multiple scan checkbox --------------------
        self.multiple_scan_var = BooleanVar(value=False)
        self.multiple_scan_btn = Checkbutton(
            self, 
            # text='Multiple Chain Full Scan', 
            command=lambda: self.multiple_scan_select(),
            variable=self.multiple_scan_var,
            onvalue=True,
            offvalue=False)

        # self.multiple_scan_btn = Button(
        #     self,
        #     image=self.checkbox_yellow_img,
        #     borderwidth=0,
        #     highlightthickness=0,
        #     command=lambda: self.multiple_scan_select(),
        #     relief="flat"
        # )
        self.multiple_scan_btn.place(
            x=16.0,
            y=308.0,
            width=20.0,
            height=20.0
        )
        
        canvas.create_text(
            47.0,
            306.0,
            anchor="nw",
            text="Multiple Chain Full Scan",
            fill="#000000",
            font=("Inter", 20 * -1)
        )

        # Text box to show results --------------------
        self.scan_synth_result = Text(
            self,
            bd=0,
            bg="#D9D9D9",
            font=("Courier", 9),
            highlightthickness=0,
            width=35, #39
            height=23 #34
        )
        self.scan_synth_result.place(
                x=275.0, #16
                y=154.0
            )
        self.scan_synth_result.config(state="disabled")

        

        # Entry Si port name --------------------
        self.si_port_name_single_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 11'),
            foreground="black"
            )
        self.si_port_name_single_entry.place(
                x=121.0, #398
                y=182.0, #182
                width=135.0, #120
                height=40.0 #40
            )
        # Add text in Entry box for placeholder
        self.si_port_name_single_entry.insert(0, 'Enter Si Port Name')
        # Use bind method for deleting placeholder on click and rewrite it on leaving (if it's empty)
        self.si_port_name_single_entry.bind("<Button-1>", self.click_si_port_single_ent)
        self.si_port_name_single_entry.bind("<Leave>", self.leave_si_port_single_ent)
        self.si_port_name_single_entry.config(state="disabled")
        canvas.create_text(
            19.0,
            192.0,
            anchor="nw",
            text="Si port name:",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        # Entry So port name --------------------
        self.so_port_name_single_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 11'),
            foreground="black"
            )
        self.so_port_name_single_entry.place(
                x=121.0,
                y=239.0,
                width=135.0,
                height=40.0
            )
        # Add text in Entry box for placeholder
        self.so_port_name_single_entry.insert(0, 'Enter So Port Name')
        # Use bind method for deleting placeholder on click and rewrite it on leaving (if it's empty)
        self.so_port_name_single_entry.bind("<Button-1>", self.click_so_port_single_ent)
        self.so_port_name_single_entry.bind("<Leave>", self.leave_so_port_single_ent)
        self.so_port_name_single_entry.config(state="disabled")
        canvas.create_text(
            19.0,
            249.0,
            anchor="nw",
            text="So port name:",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        # Entry number of chains --------------------
        self.chain_number_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 11'),
            foreground="black"
            )
        self.chain_number_entry.place(
                x=121.0,
                y=344.0,
                width=135.0,
                height=40.0
            )
        # Add text in Entry box for placeholder
        self.chain_number_entry.insert(0, 'No. of cells in chain')
        # Use bind method for deleting placeholder on click and rewrite it on leaving (if it's empty)
        self.chain_number_entry.bind("<Button-1>", self.click_chain_num_ent)
        self.chain_number_entry.bind("<Leave>", self.leave_chain_num_ent)
        self.chain_number_entry.config(state="disabled")
        canvas.create_text(
            19.0,
            354.0,
            anchor="nw",
            text="No. of Chains:",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        # Entry Si port name for multiple scan --------------------
        self.si_port_name_multi_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 11'),
            foreground="black"
            )
        self.si_port_name_multi_entry.place(
                x=121.0,
                y=400.0,
                width=135.0,
                height=40.0
            )
        # Add text in Entry box for placeholder
        self.si_port_name_multi_entry.insert(0, 'Enter Si Port Name')
        # Use bind method for deleting placeholder on click and rewrite it on leaving (if it's empty)
        self.si_port_name_multi_entry.bind("<Button-1>", self.click_si_port_multi_ent)
        self.si_port_name_multi_entry.bind("<Leave>", self.leave_si_port_multi_ent)
        self.si_port_name_multi_entry.config(state="disabled")
        canvas.create_text(
            19.0,
            410.0,
            anchor="nw",
            text="Si port name:",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        # Entry Si port name for multiple scan --------------------
        self.so_port_name_multi_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 11'),
            foreground="black"
            )
        self.so_port_name_multi_entry.place(
                x=121.0,
                y=457.0,
                width=135.0,
                height=40.0
            )
        # Add text in Entry box for placeholder
        self.so_port_name_multi_entry.insert(0, 'Enter So Port Name')
        # Use bind method for deleting placeholder on click and rewrite it on leaving (if it's empty)
        self.so_port_name_multi_entry.bind("<Button-1>", self.click_so_port_multi_ent)
        self.so_port_name_multi_entry.bind("<Leave>", self.leave_so_port_multi_ent)
        self.so_port_name_multi_entry.config(state="disabled")
        canvas.create_text(
            19.0,
            467.0,
            anchor="nw",
            text="So port name:",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        # window.resizable(False, False)
        # window.mainloop()


        # Function Definition --------------------

    def open_log(self):
        tet = self.scan_synth_result.get(1.0)
        print(tet)

    def get_scan_info(self):
        if (self.scan_synthesis_btn["state"] == "disabled"):
            return
        elif self.end_of_info == 1.0:
            info_log = self.backend.get_scan_info("test_ready.v")
            #print(info_log[0][15:])
            self.scan_synth_result.config(state="normal")
            self.scan_synth_result.delete(1.0, tk_END)
            self.scan_synth_result.insert(tk_END, info_log[0][15:])
            self.end_of_info = "1.0" + " + " + str(len(info_log[0][15:])+1) + "c"
            #print(self.end_of_info)
            self.scan_synth_result.tag_add("if",self.end_of_info, tk_END)
            self.scan_synth_result.tag_config("if", foreground="black")
            self.scan_synth_result.config(state="disable")
            return
        else: 
            return

    def single_scan_select(self):
        if (self.single_scan_var.get()):
            if (self.multiple_scan_var.get()):
                self.multiple_scan_btn.invoke()
            self.si_port_name_single_entry.config(state="normal")
            self.so_port_name_single_entry.config(state="normal")
        else:
            self.si_port_name_single_entry.config(state="disabled")
            self.so_port_name_single_entry.config(state="disabled")

    def multiple_scan_select(self):
        if (self.multiple_scan_var.get()):
            if (self.single_scan_var.get()):
                self.single_scan_btn.invoke()
            self.chain_number_entry.config(state="normal")
            self.si_port_name_multi_entry.config(state="normal")
            self.so_port_name_multi_entry.config(state="normal")
        else:
            self.chain_number_entry.config(state="disabled")
            self.si_port_name_multi_entry.config(state="disabled")
            self.so_port_name_multi_entry.config(state="disabled")
        
    def synthesize_scan(self):
        
        # s = "(!S)"
        # if s.find('\'') > -1:
        #     print("salamammamamam")
        ### Single Chain ###
        if(self.single_scan_var.get()):
            self.scan_synth_result.config(state="normal")
            print(self.end_of_info)
            self.scan_synth_result.delete(self.end_of_info, tk_END)

            si = self.si_port_name_single_entry.get()
            so = self.so_port_name_single_entry.get()

            if( si == "Enter Si Port Name" or so == "Enter So Port Name"):
                return

            elif (bool(re.match('^[a-zA-Z0-9_$]*$',si))== False or bool(re.match('^[a-zA-Z0-9_$]*$',so))== False or si.isnumeric() == True
            or so.isnumeric() == True or si[0].isnumeric() == True or so[0].isnumeric() == True):
                report = " --- Port names are not valid\n"
                self.scan_synth_result.insert(tk_END, report)
                position = tk_END + " - " + str(len(report)+1) + "c"
                self.scan_synth_result.tag_add("si",position, tk_END)
                self.scan_synth_result.tag_config("si", foreground="#d31d00")
                self.scan_synth_result.config(state="disable")
                return
            else:
                #print(si, so)
                log, success = self.backend.scan_synth([si], [so], None)

        ### Multiple Chain ###
        elif(self.multiple_scan_var.get()):
            self.scan_synth_result.config(state="normal")
            self.scan_synth_result.delete(self.end_of_info, tk_END)

            si = self.si_port_name_multi_entry.get()
            so = self.so_port_name_multi_entry.get()
            chains = self.chain_number_entry.get()
            ## TO BE CHANGED the strings in this if must be changed
            if( si == "Enter Si Port Name" or so == "Enter So Port Name" or chains == "No. of cells in chain"):
                return
            else:
                self.scan_synth_result.delete(self.end_of_info, tk_END)
                si_list  = [x.strip() for x in si.split(',')]
                so_list  = [x.strip() for x in so.split(',')]
                chain_list = [x.strip() for x in chains.split(',')]
                print(chain_list)
                if len(si_list) == len(so_list) and len(si_list) == len(chain_list):

                    for i in range(len(so_list)):
                        if (bool(re.match('^[a-zA-Z0-9_$]*$',so_list[i]))== False or bool(re.match('^[a-zA-Z0-9_$]*$',si_list[i]))== False 
                        or so_list[i].isnumeric() == True or si_list[i].isnumeric() == True 
                        or so_list[i][0].isnumeric() == True or si_list[i][0].isnumeric() == True):
                            report = " --- Port names are not valid\n"
                            self.scan_synth_result.insert(tk_END, report)
                            position = tk_END + " - " + str(len(report)+1) + "c"
                            self.scan_synth_result.tag_add("cg",position, tk_END)
                            self.scan_synth_result.tag_config("cg", foreground="#d31d00")
                            self.scan_synth_result.config(state="disable")
                            return

                    for i in range(len(chain_list)):
                        if(bool(re.match('^[0-9]*$',chain_list[i]))== False):
                            report = " --- Chain numbers are not valid\n"
                            self.scan_synth_result.insert(tk_END, report)
                            position = tk_END + " - " + str(len(report)+1) + "c"
                            self.scan_synth_result.tag_add("bs",position, tk_END)
                            self.scan_synth_result.tag_config("bs", foreground="#d31d00")
                            self.scan_synth_result.config(state="disable")
                            return
                        chain_list[i]=int(chain_list[i])
                
                else : 
                    
                    report = " Mismatch in nubmer of\n Si, So and chains\n"
                    self.scan_synth_result.insert(tk_END, report)
                    position = tk_END + " - " + str(len(report)+1) + "c"
                    self.scan_synth_result.tag_add("bd",position, tk_END)
                    self.scan_synth_result.tag_config("bd", foreground="#d31d00")
                    self.scan_synth_result.config(state="disable")
                    return
                    
        
                log, success = self.backend.scan_synth(si_list, so_list, chain_list)
            

        ### start printing result 
        self.scan_synth_result.config(state="normal")
        self.scan_synth_result.delete(self.end_of_info, tk_END)

        tag_name = ""
        for phrase in log:
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
            self.scan_synth_result.insert(tk_END, phrase[index:])
            position = tk_END + " - " + str(len(phrase[index:])+1) + "c"
            self.scan_synth_result.tag_add(tag_name,position, tk_END)
            self.scan_synth_result.tag_config(tag_name, foreground=color)
        self.scan_synth_result.config(state="disabled")
        # self.backend.test_set_gen()
        # self.testset_btn.config(image=self.test_success_img)
        # self.openlog_testset_btn.config(image=self.openlog_img)












    # call function when we click on entry box
    def click_si_port_single_ent(*args):
        if (args[0].si_port_name_single_entry.get() == "Enter Si Port Name"):
            args[0].si_port_name_single_entry.delete(0, 'end')
    def click_si_port_multi_ent(*args):
        if (args[0].si_port_name_multi_entry.get() == "Enter Si Port Name"):
            args[0].si_port_name_multi_entry.delete(0, 'end')
    def click_so_port_single_ent(*args):
        if (args[0].so_port_name_single_entry.get() == "Enter So Port Name"):
            args[0].so_port_name_single_entry.delete(0, 'end')
    def click_so_port_multi_ent(*args):
        if (args[0].so_port_name_multi_entry.get() == "Enter So Port Name"):
            args[0].so_port_name_multi_entry.delete(0, 'end')
    def click_chain_num_ent(*args):
        if (args[0].chain_number_entry.get() == "No. of cells in chain"):
            args[0].chain_number_entry.delete(0, 'end')
    
    # call function when we leave entry box
    def leave_si_port_single_ent(*args):
        if (args[0].si_port_name_single_entry.get() == ""):
            args[0].si_port_name_single_entry.delete(0, 'end')
            args[0].si_port_name_single_entry.insert(0, 'Enter Si Port Name')
        args[0].focus()
    def leave_si_port_multi_ent(*args):
        if (args[0].si_port_name_multi_entry.get() == ""):
            args[0].si_port_name_multi_entry.delete(0, 'end')
            args[0].si_port_name_multi_entry.insert(0, 'Enter Si Port Name')
        args[0].focus()
    def leave_so_port_single_ent(*args):
        if (args[0].so_port_name_single_entry.get() == ""):
            args[0].so_port_name_single_entry.delete(0, 'end')
            args[0].so_port_name_single_entry.insert(0, 'Enter So Port Name')
        args[0].focus()
    def leave_so_port_multi_ent(*args):
        if (args[0].so_port_name_multi_entry.get() == ""):
            args[0].so_port_name_multi_entry.delete(0, 'end')
            args[0].so_port_name_multi_entry.insert(0, 'Enter So Port Name')
        args[0].focus()
    def leave_chain_num_ent(*args):
        if (args[0].chain_number_entry.get() == ""):
            args[0].chain_number_entry.delete(0, 'end')
            args[0].chain_number_entry.insert(0, 'Enter no. of chain')
        args[0].focus()
