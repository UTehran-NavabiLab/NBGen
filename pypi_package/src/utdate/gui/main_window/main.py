from pathlib import Path
from tkinter import (
    Toplevel,
    Frame,
    Canvas,
    Button,
    Entry,
    PhotoImage,
    messagebox,
    StringVar,
    Label
)

from utdate.gui.file.main import InputFile
from utdate.gui.synthesis.main import Synthesis
from utdate.gui.DRC.main import DRC
from utdate.gui.scan.main import Scan
from utdate.gui.atpg_fltg.main import ATPG_FLTG # must change to atpg_fltg
from utdate.gui.faultSim.main import FaultSim
from utdate.gui.bist.main import Bist

OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / Path("./assets")


def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)


def mainWindow(backend):
    MainWindow(backend)


class MainWindow(Toplevel):

    def __init__(self, backend, *args, **kwargs):
        Toplevel.__init__(self, *args, **kwargs)

        self.title("DATE: Design and Test Environment")

        self.current_window = None
        self.current_window_label = StringVar()

        # Add a frame rectangle
        self.sidebar_indicator = Frame(self, background="#EE5959")


        self.geometry("800x600")
        self.configure(bg = "#FFFFFF")


        self.canvas = Canvas(
            self,
            bg = "#FFFFFF",
            height = 600,
            width = 800,
            bd = 0,
            highlightthickness = 0,
            relief = "ridge"
        )

        self.canvas.place(x = 0, y = 0)
        self.canvas.create_rectangle(
            0.0,
            0,
            800.0,
            600.0,
            fill="#FFFFFF",
            outline="")
        
        self.canvas.create_rectangle(
            250.0,
            0,
            800.0,
            8.000000000000007,
            fill="#EE5959",
            outline="")

        self.canvas.create_rectangle(
            0.0,
            0,
            250.0,
            600.0,
            fill="#222020",
            outline="")


        exit_btn_image_6 = PhotoImage(
            file=relative_to_assets("exit.png"))
        self.exit_btn = Button(
            self.canvas,
            image=exit_btn_image_6,
            borderwidth=0,
            highlightthickness=0,
            command= self.exit,
            relief="flat"
        )
        self.exit_btn.place(
            x=4.0,
            y=2,
            width=12.0,
            height=12.0
        )

        resize_btn_image_7 = PhotoImage(
            file=relative_to_assets("maximize.png"))
        self.resize_btn = Button(
            self.canvas,
            image=resize_btn_image_7,
            borderwidth=0,
            highlightthickness=0,
          #  command=lambda: self.handle_btn_press("scan"),
            relief="flat"
        )
        self.resize_btn.place(
            x=19.0,
            y=2,
            width=12.0,
            height=12.0
        )

        button_image_8 = PhotoImage(
            file=relative_to_assets("minimize.png"))
        self.button_8 = Button(
            self.canvas,
            image=button_image_8,
            borderwidth=0,
            highlightthickness=0,
            #command=lambda: self.handle_btn_press("scan"),
            relief="flat"
        )
        self.button_8.place(
            x=33.0,
            y=2,
            width=12.0,
            height=12.0
        )

        file_btn_image_1 = PhotoImage(
            file=relative_to_assets("file.png"))
        self.file_btn = Button(
            self.canvas,
            image=file_btn_image_1,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.handle_btn_press("file"),
            relief="flat"
        )
        self.file_btn.place(
            x=0.0,
            y=60.0,
            width=250.0,
            height=60.0
        )

        synth_btn_image_2 = PhotoImage(
            file=relative_to_assets("synth.png"))
        self.synth_btn = Button(
            self.canvas,
            image=synth_btn_image_2,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.handle_btn_press("synth"),
            relief="flat"
        )
        self.synth_btn.place(
            x=0.0,
            y=120.0,
            width=250.0,
            height=60.0
        )

        drc_btn_image_5 = PhotoImage(
            file=relative_to_assets("drc.png"))
        self.drc_btn = Button(
            self.canvas,
            image=drc_btn_image_5,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.handle_btn_press("drc"),
            relief="flat"
        )
        self.drc_btn.place(
            x=0.0,
            y=180.0,
            width=250.0,
            height=60.0
        )
        
        scan_btn_image_5 = PhotoImage(
            file=relative_to_assets("scan.png"))
        self.scan_btn = Button(
            self.canvas,
            image=scan_btn_image_5,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.handle_btn_press("scan"),
            relief="flat"
        )
        self.scan_btn.place(
            x=0.0,
            y=240.0,
            width=250.0,
            height=60.0
        )

        atpg_fltg_btn_image_3 = PhotoImage(
            file=relative_to_assets("atpg_fltg.png"))
        self.atpg_fltg_btn = Button(
            self.canvas,
            image=atpg_fltg_btn_image_3,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.handle_btn_press("atpg_fltg"),
            relief="flat"
        )
        self.atpg_fltg_btn.place(
            x=0.0,
            y=298.0,
            width=250.0,
            height=60.0
        )

        faultSim_btn_image_4 = PhotoImage(
            file=relative_to_assets("fault_sim.png"))
        self.faultSim_btn = Button(
            self.canvas,
            image=faultSim_btn_image_4,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.handle_btn_press("faultsim"),
            relief="flat"
        )
        self.faultSim_btn.place(
            x=0.0,
            y=360.0,
            width=250.0,
            height=60.0
        )

        bist_btn_image_4 = PhotoImage(
            file=relative_to_assets("bist.png"))
        self.bist_btn = Button(
            self.canvas,
            image=bist_btn_image_4,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.handle_btn_press("bist"),
            relief="flat"
        )
        self.bist_btn.place(
            x=0.0,
            y=420.0,
            width=250.0,
            height=60.0
        )

        about_btn_image_4 = PhotoImage(
            file=relative_to_assets("about.png"))
        self.about_btn = Button(
            self.canvas,
            image=about_btn_image_4,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.handle_btn_press("about"),
            relief="flat"
        )
        self.about_btn.place(
            x=0.0,
            y=480.0,
            width=250.0,
            height=60.0
        )

        # Loop through windows and place them
        self.windows = {
            "file": InputFile(self, backend),
            "synth": Synthesis(self, backend),
            "drc": DRC(self, backend),
            "scan": Scan(self, backend),
            "atpg_fltg": ATPG_FLTG(self, backend),
            "faultsim": FaultSim(self, backend),
            "bist": Bist(self, backend)
            # "about": About(self, backend)
        }
        self.sidebar_indicator_y ={
            "file": (60 * 1),
            "synth": (60 * 2),
            "drc": (60 * 3),
            "scan": (60 * 4),
            "atpg_fltg": (60 * 5),
            "faultsim": (60 * 6),
            "bist": (60 * 7),
            # "about": (60 * 1),
        }

        # self.handle_btn_press(self.file_btn, "file")
        self.create_all_pages()
        # # self.sidebar_indicator.place(x=0, y=0)

        # self.current_window.place(x=0, y=0, width=800.0, height=600.0)

        # self.current_window.tkraise()
        self.resizable(False, False)
        self.overrideredirect(True)

        self.grip1 = Label(self, width=200, bg="#222020",)
        self.grip1.place(
            x=50.0,
            y=0.0,
        )
        self.grip1.bind("<ButtonPress-1>", self.start_move)
        self.grip1.bind("<ButtonRelease-1>", self.stop_move)
        self.grip1.bind("<B1-Motion>", self.do_move)
        
        self.grip2 = Label(self, width=550, bg="#EE5959")
        self.grip2.place(
            x=250.0,
            y=0.0,
        )
        self.grip2.bind("<ButtonPress-1>", self.start_move)
        self.grip2.bind("<ButtonRelease-1>", self.stop_move)
        self.grip2.bind("<B1-Motion>", self.do_move)

        # self.bind('<B1-Motion>',self.move)
        self.mainloop()

    def place_sidebar_indicator(self):
        pass

    # def logout(self):
    #     confirm = messagebox.askyesno(
    #         "Confirm log-out", "Do you really want to log out?"
    #     )
    #     if confirm == True:
    #         user = None
    #         self.destroy()
    #         login.gui.loginWindow()

    def create_all_pages(self):
        
        for window in self.windows.values():
            window.place(x=250, y=0, width=550.0, height=600.0)
        
        self.windows["file"].tkraise()
        # Place the sidebar_indicator on respective button
        self.sidebar_indicator.place(x=0, y=self.sidebar_indicator_y["file"], height=60, width=10)
        self.sidebar_indicator.tkraise()



    def handle_btn_press(self, name):
        if (name in self.windows):
            # Place the sidebar on respective button
            self.sidebar_indicator.place(x=0, y=self.sidebar_indicator_y[name], height=60, width=10)

            if(name == "synth"):
                self.windows[name].display_files()

            if (name == "scan"):
                self.windows[name].get_scan_info()

            # Set current Window
            self.current_window = self.windows.get(name)

            # raise the frame of the button pressed to top
            self.windows[name].tkraise()
            self.sidebar_indicator.tkraise()

            self.grip2 = Label(self, width=550, bg="#EE5959")
            self.grip2.place(
                x=250.0,
                y=0.0,
            )
            self.grip2.bind("<ButtonPress-1>", self.start_move)
            self.grip2.bind("<ButtonRelease-1>", self.stop_move)
            self.grip2.bind("<B1-Motion>", self.do_move)

            # # Handle label change
            # current_name = self.windows.get(name)._name.split("!")[-1].capitalize()
            # self.canvas.itemconfigure(self.heading, text=current_name)

    def handle_dashboard_refresh(self):
        # Recreate the dash window
        self.windows["file"] = InputFile(self)

    def move(self, event):
        # self.geometry("+"+str(int(event.x))+"+"+str(int(event.y)))
        x, y = self.winfo_pointerxy()
        self.geometry(f"+{x}+{y}")


    def start_move(self, event):
        self.x = event.x
        self.y = event.y

    def stop_move(self, event):
        self.x = None
        self.y = None

    def do_move(self, event):
        deltax = event.x - self.x
        deltay = event.y - self.y
        x = self.winfo_x() + deltax
        y = self.winfo_y() + deltay
        self.geometry(f"+{x}+{y}")

    def exit(self):
        quit()