from pathlib import Path
from tkinter import Tk, Frame, Canvas, Entry, Text, Button, PhotoImage, Checkbutton, BooleanVar

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
        # Buttons: design rule check --------------------
        self.design_rule_check_img = PhotoImage(
            file=relative_to_assets("design_rule_check.png"))
        # TODO:
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
            x=16,
            y=515.0,
            width=240.0,
            height=37.0
        )

        # Buttons: scan synthesis --------------------
        self.scan_synthesis_img = PhotoImage(
            file=relative_to_assets("scan_synthesis.png"))
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
            image=self.scan_synthesis_img,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.synthesize_scan(),
            relief="flat"
        )
        self.scan_synthesis_btn.place(
            x=278.0,
            y=515.0,
            width=240.0,
            height=37.0
        )
        # TODO:
        #   should it be disable at first??
        # self.scan_synthesis_btn.config(state="disabled")

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
            x=275.0,
            y=155.0,
            width=20.0,
            height=20.0
        )

        canvas.create_text(
            306.0,
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
            x=275.0,
            y=308.0,
            width=20.0,
            height=20.0
        )
        
        canvas.create_text(
            306.0,
            306.0,
            anchor="nw",
            text="Multiple Chain Full Scan",
            fill="#000000",
            font=("Inter", 20 * -1)
        )

        # Text box to show results --------------------
        self.rule_check_result = Text(
            self,
            bd=0,
            bg="#D9D9D9",
            font=("Courier", 10),
            highlightthickness=0,
            width=39,
            height=34
        )
        self.rule_check_result.place(
                x=16.0,
                y=154.0
            )
        self.rule_check_result.config(state="disabled")

        # entry_image_1 = PhotoImage(
        #     file=relative_to_assets("entry_1.png"))
        # entry_bg_1 = canvas.create_image(
        #     136.0,
        #     325.5,
        #     image=entry_image_1
        # )
        # entry_1 = Text(
        #     bd=0,
        #     bg="#EBEBEB",
        #     fg="#EBEBEB",
        #     highlightthickness=0
        # )
        # entry_1.place(
        #     x=16.0,
        #     y=154.0,
        #     width=240.0,
        #     height=341.0
        # )
        # Shape: centered gray rectangle ------------------
        # canvas.create_rectangle(
        #     16.0,
        #     154.0,
        #     (16.0 + 240),
        #     (154.0 + 343),
        #     fill="#EBEBEB",
        #     outline="")

        # Entry Si port name --------------------
        self.si_port_name_single_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 12'),
            foreground="black"
            )
        self.si_port_name_single_entry.place(
                x=398.0,
                y=182.0,
                width=120.0,
                height=40.0
            )
        # Add text in Entry box for placeholder
        self.si_port_name_single_entry.insert(0, 'Enter Si Port Name')
        # Use bind method for deleting placeholder on click and rewrite it on leaving (if it's empty)
        self.si_port_name_single_entry.bind("<Button-1>", self.click_si_port_single_ent)
        self.si_port_name_single_entry.bind("<Leave>", self.leave_si_port_single_ent)
        self.si_port_name_single_entry.config(state="disabled")
        canvas.create_text(
            278.0,
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
            font=('Helvetica 12'),
            foreground="black"
            )
        self.so_port_name_single_entry.place(
                x=398.0,
                y=239.0,
                width=120.0,
                height=40.0
            )
        # Add text in Entry box for placeholder
        self.so_port_name_single_entry.insert(0, 'Enter So Port Name')
        # Use bind method for deleting placeholder on click and rewrite it on leaving (if it's empty)
        self.so_port_name_single_entry.bind("<Button-1>", self.click_so_port_single_ent)
        self.so_port_name_single_entry.bind("<Leave>", self.leave_so_port_single_ent)
        self.so_port_name_single_entry.config(state="disabled")
        canvas.create_text(
            278.0,
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
            font=('Helvetica 12'),
            foreground="black"
            )
        self.chain_number_entry.place(
                x=398.0,
                y=344.0,
                width=120.0,
                height=40.0
            )
        # Add text in Entry box for placeholder
        self.chain_number_entry.insert(0, 'Enter no. of chain')
        # Use bind method for deleting placeholder on click and rewrite it on leaving (if it's empty)
        self.chain_number_entry.bind("<Button-1>", self.click_chain_num_ent)
        self.chain_number_entry.bind("<Leave>", self.leave_chain_num_ent)
        self.chain_number_entry.config(state="disabled")
        canvas.create_text(
            278.0,
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
            font=('Helvetica 12'),
            foreground="black"
            )
        self.si_port_name_multi_entry.place(
                x=398.0,
                y=400.0,
                width=120.0,
                height=40.0
            )
        # Add text in Entry box for placeholder
        self.si_port_name_multi_entry.insert(0, 'Enter Si Port Name')
        # Use bind method for deleting placeholder on click and rewrite it on leaving (if it's empty)
        self.si_port_name_multi_entry.bind("<Button-1>", self.click_si_port_multi_ent)
        self.si_port_name_multi_entry.bind("<Leave>", self.leave_si_port_multi_ent)
        self.si_port_name_multi_entry.config(state="disabled")
        canvas.create_text(
            278.0,
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
            font=('Helvetica 12'),
            foreground="black"
            )
        self.so_port_name_multi_entry.place(
                x=398.0,
                y=457.0,
                width=120.0,
                height=40.0
            )
        # Add text in Entry box for placeholder
        self.so_port_name_multi_entry.insert(0, 'Enter So Port Name')
        # Use bind method for deleting placeholder on click and rewrite it on leaving (if it's empty)
        self.so_port_name_multi_entry.bind("<Button-1>", self.click_so_port_multi_ent)
        self.so_port_name_multi_entry.bind("<Leave>", self.leave_so_port_multi_ent)
        self.so_port_name_multi_entry.config(state="disabled")
        canvas.create_text(
            278.0,
            467.0,
            anchor="nw",
            text="So port name:",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        # window.resizable(False, False)
        # window.mainloop()


        # Function Definition --------------------
    def check_design_rules(self):
        pass
        # self.testbench_name = self.testbench_name_entry.get()
        # self.instance_name = self.instance_name_entry.get()

        # self.backend.faultCollapsing(self.testbench_name,  self.instance_name)

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
        pass
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
        if (args[0].chain_number_entry.get() == "Enter no. of chain"):
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
