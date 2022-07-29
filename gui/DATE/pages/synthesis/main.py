
from pathlib import Path

# from tkinter import *
# Explicit imports to satisfy Flake8
from tkinter import Tk, Frame, Canvas, Entry, Text, Button, PhotoImage


OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / Path("./assets")


def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)

def synthesis():
    Synthesis()


class Synthesis(Frame):
    def __init__(self, parent, controller=None, *args, **kwargs):
        Frame.__init__(self, parent, *args, **kwargs)
        self.parent = parent

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
            1.4210854715202004e-14,
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
            28.0,
            122.0,
            anchor="nw",
            text="Sythesis Report",
            fill="#000000",
            font=("Inter", 20 * -1)
        )

        canvas.create_rectangle(
            389.0,
            468.0,
            545.0,
            506.0,
            fill="#000000",
            outline="")

        canvas.button_image_1 = PhotoImage(
            file=relative_to_assets("button_1.png"))
        button_1 = Button(
            self,
            image=canvas.button_image_1,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: print("button_1 clicked"),
            relief="flat"
        )
        button_1.place(
            x=28.0,
            y=527.0,
            width=340.0,
            height=37.0
        )

        canvas.create_text(
            12.0,
            20.0,
            anchor="nw",
            text="Synthesis",
            fill="#FFFFFF",
            font=("Inter", 24 * -1)
        )

        canvas.entry_image_1 = PhotoImage(
            file=relative_to_assets("entry_1.png"))
        entry_bg_1 = canvas.create_image(
            198.0,
            336.0,
            image=canvas.entry_image_1
        )
        entry_1 = Text(
            self,
            bd=0,
            bg="#EAEAEA",
            highlightthickness=0
        )
        entry_1.place(
            x=28.0,
            y=166.0,
            width=340.0,
            height=338.0
        )
        # window.resizable(False, False)
        # window.mainloop()
