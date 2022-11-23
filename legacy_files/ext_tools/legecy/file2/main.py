
from pathlib import Path

# from tkinter import *
# Explicit imports to satisfy Flake8
from tkinter import Tk, Frame, Canvas, Entry, Text, Button, PhotoImage


OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / Path("./assets")


def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)

def inputFile():
    InputFile()


class InputFile(Frame):
    def __init__(self, parent, controller=None, *args, **kwargs):
        Frame.__init__(self, parent, *args, **kwargs)
        self.parent = parent

        # self.geometry("800x600")
        self.configure(bg = "#FFFFFF")


        canvas = Canvas(
            self,
            bg = "#FFAAFF",
            height = 600,
            width = 550,
            bd = 0,
            highlightthickness = 0,
            relief = "ridge"
        )
    
        canvas.place(x = 0, y = 0)
        canvas.image_image_1 = PhotoImage(
            file=relative_to_assets("image_1.png"))
        image_1 = canvas.create_image(
            318.0,
            35.00000000000001,
            image=canvas.image_image_1
        )

        canvas.image_image_2 = PhotoImage(
            file=relative_to_assets("image_2.png"))
        image_2 = canvas.create_image(
            740.0,
            68.0,
            image=canvas.image_image_2
        )

        canvas.create_rectangle(
            278.0,
            166.0,
            618.0,
            506.0,
            fill="#EAEAEA",
            outline="")

        canvas.entry_image_1 = PhotoImage(
            file=relative_to_assets("entry_1.png"))
        entry_bg_1 = canvas.create_image(
            448.0,
            183.0,
            image=canvas.entry_image_1
        )
        entry_1 = Entry(
            bd=0,
            bg="#D9D9D9",
            highlightthickness=0
        )
        entry_1.place(
            x=278.0,
            y=166.0,
            width=340.0,
            height=32.0
        )

        canvas.button_image_9 = PhotoImage(
            file=relative_to_assets("button_9.png"))
        button_9 = Button(
            image=canvas.button_image_9,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: print("button_9 clicked"),
            relief="flat"
        )
        button_9.place(
            x=587.0,
            y=173.0,
            width=20.0,
            height=20.0
        )

        canvas.create_text(
            278.0,
            112.0,
            anchor="nw",
            text="Input Files: (In Order of compilation)",
            fill="#000000",
            font=("Inter", 20 * -1)
        )

        canvas.create_rectangle(
            639.0,
            480.0,
            698.0,
            499.0,
            fill="#000000",
            outline="")

        canvas.create_rectangle(
            640.0,
            455.0,
            699.0,
            474.0,
            fill="#000000",
            outline="")

        canvas.button_image_10 = PhotoImage(
            file=relative_to_assets("button_10.png"))
        button_10 = Button(
            image=canvas.button_image_10,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: print("button_10 clicked"),
            relief="flat"
        )
        button_10.place(
            x=278.0,
            y=527.0,
            width=340.0,
            height=37.0
        )

        canvas.create_text(
            294.0,
            15.999999999999993,
            anchor="nw",
            text="File",
            fill="#FFFFFF",
            font=("Inter", 32 * -1)
        )
        # window.resizable(False, False)
        # window.mainloop()
