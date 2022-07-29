
from pathlib import Path

# from tkinter import *
# Explicit imports to satisfy Flake8
from tkinter import Tk, Frame, Canvas, Entry, Text, Button, PhotoImage


OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / Path("./assets")


def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)

def test():
    Test()


class Test(Frame):
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
            2.842170943040401e-14,
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

        canvas.entry_image_1 = PhotoImage(
            file=relative_to_assets("entry_1.png"))
        entry_bg_1 = canvas.create_image(
            279.5,
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
            x=19.0,
            y=166.0,
            width=521.0,
            height=338.0
        )

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
            x=19.0,
            y=526.0,
            width=159.0,
            height=37.0
        )

        canvas.button_image_2 = PhotoImage(
            file=relative_to_assets("button_2.png"))
        button_2 = Button(
            self,
            image=canvas.button_image_2,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: print("button_2 clicked"),
            relief="flat"
        )
        button_2.place(
            x=200.0,
            y=526.0,
            width=159.0,
            height=37.0
        )

        canvas.button_image_3 = PhotoImage(
            file=relative_to_assets("button_3.png"))
        button_3 = Button(
            self,
            image=canvas.button_image_3,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: print("button_3 clicked"),
            relief="flat"
        )
        button_3.place(
            x=381.0,
            y=526.0,
            width=159.0,
            height=37.0
        )

        canvas.create_text(
            35.0,
            15.0,
            anchor="nw",
            text="Test",
            fill="#FFFFFF",
            font=("Inter", 32 * -1)
        )
        # window.resizable(False, False)
        # window.mainloop()
