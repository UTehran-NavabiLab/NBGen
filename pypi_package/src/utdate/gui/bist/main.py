from pathlib import Path
from tkinter import Tk, Frame, Canvas, Entry, Text, Button, PhotoImage, Checkbutton, BooleanVar

OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / Path("./assets")


def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)

def Bist(backend):
    Bist(backend)


class Bist(Frame):
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
            text="BIST",
            fill="#FFFFFF",
            font=("Inter", 21 * -1)
        )
        # Buttons: insert_bist --------------------
        self.insert_bist_img = PhotoImage(
            file=relative_to_assets("insert_bist.png"))
        self.insert_bist_btn = Button(
            self,
            image=self.insert_bist_img,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.insert_bist(),
            relief="flat"
        )
        self.insert_bist_btn.place(
            x=105.0,
            y=487.0,
            width=340.0,
            height=37.0
        )
        #-----------
        # Entry PRGP properties --------------------
        canvas.create_text(
            13.0,
            134.0,
            anchor="nw",
            text="PRPG",
            fill="#000000",
            font=("Inter", 20 * -1)
        )
        # ---- PRPG: SEED
        canvas.create_text(
            13.0,
            179.0,
            anchor="nw",
            text="Seed",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        self.prpg_seed_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 12'),
            foreground="black"
            )
        self.prpg_seed_entry.place(
                x=112.0,
                y=169.0,
                width=140.0,
                height=40.0
            )

        # ---- PRPG: POLY
        canvas.create_text(
            13.0,
            236.0,
            anchor="nw",
            text="Polynomial",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        self.prpg_poly_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 12'),
            foreground="black"
            )
        self.prpg_poly_entry.place(
                x=112.0,
                y=226.0,
                width=140.0,
                height=40.0
            )
        
        # Entry MISR properties --------------------
        canvas.create_text(
            290.0,
            134.0,
            anchor="nw",
            text="MISR",
            fill="#000000",
            font=("Inter", 20 * -1)
        )
        # ---- MISR: SEED
        canvas.create_text(
            290.0,
            179.0,
            anchor="nw",
            text="Seed",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        self.misr_seed_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 12'),
            foreground="black"
            )
        self.misr_seed_entry.place(
                x=389.0,
                y=169.0,
                width=140.0,
                height=40.0
            )

        # ---- MISR: POLY
        canvas.create_text(
            290.0,
            236.0,
            anchor="nw",
            text="Polynomial",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        self.misr_poly_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 12'),
            foreground="black"
            )
        self.misr_poly_entry.place(
                x=389.0,
                y=226.0,
                width=140.0,
                height=40.0
            )
        
        # Entry SRSG properties --------------------
        canvas.create_text(
            13.0,
            293.0,
            anchor="nw",
            text="SRSG",
            fill="#000000",
            font=("Inter", 20 * -1)
        )
        # ---- SRSG: SEED
        canvas.create_text(
            13.0,
            338.0,
            anchor="nw",
            text="Seed",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        self.srsg_seed_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 12'),
            foreground="black"
            )
        self.srsg_seed_entry.place(
                x=112.0,
                y=328.0,
                width=140.0,
                height=40.0
            )

        # ---- SRSG: POLY
        canvas.create_text(
            13.0,
            395.0,
            anchor="nw",
            text="Polynomial",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        self.srsg_poly_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 12'),
            foreground="black"
            )
        self.srsg_poly_entry.place(
                x=112.0,
                y=385.0,
                width=140.0,
                height=40.0
            )
        
        # Entry SISA properties --------------------
        canvas.create_text(
            290.0,
            293.0,
            anchor="nw",
            text="SISA",
            fill="#000000",
            font=("Inter", 20 * -1)
        )
        # ---- SISA: SEED
        canvas.create_text(
            290.0,
            338.0,
            anchor="nw",
            text="Seed",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        self.sisa_seed_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 12'),
            foreground="black"
            )
        self.sisa_seed_entry.place(
                x=389.0,
                y=328.0,
                width=140.0,
                height=40.0
            )

        # ---- SISA: POLY
        canvas.create_text(
            290.0,
            395.0,
            anchor="nw",
            text="Polynomial",
            fill="#000000",
            font=("Inter", 16 * -1)
        )

        self.sisa_poly_entry = Entry(
            self,
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0,
            border=1,
            font=('Helvetica 12'),
            foreground="black"
            )
        self.sisa_poly_entry.place(
                x=389.0,
                y=385.0,
                width=140.0,
                height=40.0
            )


        # Function Definition --------------------
    def insert_bist(self):
        input_bist_configuration = dict()
        
        #   TODO:
        #   Check each parameter not be empty, otherwise raise exception
        # if ((self.prpg_seed_entry.get() != "") and (self.prpg_poly_entry.get() != "") 
            # and (self.misr_seed_entry.get() != "") and (self.misr_poly_entry.get() != "")
            # and (self.srsg_seed_entry.get() != "") and (self.srsg_poly_entry.get() != "")
            # and (self.sisa_seed_entry.get() != "") and (self.sisa_poly_entry.get() != "")):
            # create bist configuration
        input_bist_configuration.update({"bist_type": "RTS"})
        input_bist_configuration.update({"prpg_seed": self.prpg_seed_entry.get()})
        input_bist_configuration.update({"prpg_poly": self.prpg_poly_entry.get()})
        input_bist_configuration.update({"misr_seed": self.misr_seed_entry.get()})
        input_bist_configuration.update({"misr_poly": self.misr_poly_entry.get()})
        input_bist_configuration.update({"srsg_seed": self.srsg_seed_entry.get()})
        input_bist_configuration.update({"srsg_poly": self.srsg_poly_entry.get()})
        input_bist_configuration.update({"sisa_seed": self.sisa_seed_entry.get()})
        input_bist_configuration.update({"sisa_poly": self.sisa_poly_entry.get()})
        
        self.backend.insert_bist(input_bist_configuration)
        # else:
        #     print("Error: At least one the parameters are empty")
            
