
# This file was generated by the Tkinter Designer by Parth Jadhav
# https://github.com/ParthJadhav/Tkinter-Designer


from pathlib import Path

# from tkinter import *
# Explicit imports to satisfy Flake8
from tkinter import Tk, Canvas, Entry, Text, Button, PhotoImage


OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / Path("./assets")


def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)


window = Tk()

window.geometry("800x600")
window.configure(bg = "#FFFFFF")


canvas = Canvas(
    window,
    bg = "#FFFFFF",
    height = 600,
    width = 800,
    bd = 0,
    highlightthickness = 0,
    relief = "ridge"
)

canvas.place(x = 0, y = 0)
canvas.create_rectangle(
    0.0,
    0.0,
    800.0,
    600.0,
    fill="#FFFFFF",
    outline="")

canvas.create_rectangle(
    0.0,
    0.0,
    250.0,
    600.0,
    fill="#222020",
    outline="")

canvas.create_rectangle(
    250.0,
    0.0,
    800.0,
    8.0,
    fill="#EE5959",
    outline="")

button_image_1 = PhotoImage(
    file=relative_to_assets("button_1.png"))
button_1 = Button(
    image=button_image_1,
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_1 clicked"),
    relief="flat"
)
button_1.place(
    x=0.0,
    y=134.0,
    width=250.0,
    height=60.0
)

button_image_2 = PhotoImage(
    file=relative_to_assets("button_2.png"))
button_2 = Button(
    image=button_image_2,
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_2 clicked"),
    relief="flat"
)
button_2.place(
    x=0.0,
    y=194.0,
    width=250.0,
    height=60.0
)

button_image_3 = PhotoImage(
    file=relative_to_assets("button_3.png"))
button_3 = Button(
    image=button_image_3,
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_3 clicked"),
    relief="flat"
)
button_3.place(
    x=0.0,
    y=254.0,
    width=250.0,
    height=60.0
)

button_image_4 = PhotoImage(
    file=relative_to_assets("button_4.png"))
button_4 = Button(
    image=button_image_4,
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_4 clicked"),
    relief="flat"
)
button_4.place(
    x=0.0,
    y=314.0,
    width=250.0,
    height=60.0
)

button_image_5 = PhotoImage(
    file=relative_to_assets("button_5.png"))
button_5 = Button(
    image=button_image_5,
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_5 clicked"),
    relief="flat"
)
button_5.place(
    x=0.0,
    y=374.0,
    width=250.0,
    height=60.0
)

button_image_6 = PhotoImage(
    file=relative_to_assets("button_6.png"))
button_6 = Button(
    image=button_image_6,
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_6 clicked"),
    relief="flat"
)
button_6.place(
    x=4.0,
    y=2.0,
    width=12.0,
    height=12.0
)

button_image_7 = PhotoImage(
    file=relative_to_assets("button_7.png"))
button_7 = Button(
    image=button_image_7,
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_7 clicked"),
    relief="flat"
)
button_7.place(
    x=19.0,
    y=2.0,
    width=12.0,
    height=12.0
)

button_image_8 = PhotoImage(
    file=relative_to_assets("button_8.png"))
button_8 = Button(
    image=button_image_8,
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_8 clicked"),
    relief="flat"
)
button_8.place(
    x=33.0,
    y=2.0,
    width=12.0,
    height=12.0
)

image_image_1 = PhotoImage(
    file=relative_to_assets("image_1.png"))
image_1 = canvas.create_image(
    318.0,
    35.0,
    image=image_image_1
)

image_image_2 = PhotoImage(
    file=relative_to_assets("image_2.png"))
image_2 = canvas.create_image(
    740.0,
    68.0,
    image=image_image_2
)

button_image_9 = PhotoImage(
    file=relative_to_assets("button_9.png"))
button_9 = Button(
    image=button_image_9,
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_9 clicked"),
    relief="flat"
)
button_9.place(
    x=278.0,
    y=524.0,
    width=340.0,
    height=37.0
)

button_image_10 = PhotoImage(
    file=relative_to_assets("button_10.png"))
button_10 = Button(
    image=button_image_10,
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_10 clicked"),
    relief="flat"
)
button_10.place(
    x=632.0,
    y=469.0,
    width=159.0,
    height=37.0
)

button_image_11 = PhotoImage(
    file=relative_to_assets("button_11.png"))
button_11 = Button(
    image=button_image_11,
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_11 clicked"),
    relief="flat"
)
button_11.place(
    x=632.0,
    y=362.0,
    width=159.0,
    height=37.0
)

canvas.create_text(
    254.0,
    8.0,
    anchor="nw",
    text="Fault ",
    fill="#FFFFFF",
    font=("Inter", 24 * -1)
)

canvas.create_text(
    254.0,
    37.0,
    anchor="nw",
    text="Simulation",
    fill="#FFFFFF",
    font=("Inter", 24 * -1)
)

entry_image_1 = PhotoImage(
    file=relative_to_assets("entry_1.png"))
entry_bg_1 = canvas.create_image(
    448.0,
    336.0,
    image=entry_image_1
)
entry_1 = Text(
    bd=0,
    bg="#EAEAEA",
    highlightthickness=0
)
entry_1.place(
    x=278.0,
    y=166.0,
    width=340.0,
    height=338.0
)

canvas.create_text(
    278.0,
    122.0,
    anchor="nw",
    text="Simulation Report",
    fill="#000000",
    font=("Inter", 20 * -1)
)

canvas.create_rectangle(
    622.0,
    341.0,
    632.2481689453125,
    350.0,
    fill="#000000",
    outline="")

canvas.create_rectangle(
    622.0,
    444.0,
    632.2481689453125,
    453.0,
    fill="#000000",
    outline="")

canvas.create_text(
    638.0,
    336.0,
    anchor="nw",
    text="Use existing Fault list",
    fill="#000000",
    font=("Inter", 15 * -1)
)

canvas.create_text(
    638.0,
    439.0,
    anchor="nw",
    text="Use existing Test set",
    fill="#000000",
    font=("Inter", 15 * -1)
)
window.resizable(False, False)
window.mainloop()