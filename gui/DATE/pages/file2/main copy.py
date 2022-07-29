
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
    7.105427357601002e-15,
    800.0,
    600.0,
    fill="#FFFFFF",
    outline="")

canvas.create_rectangle(
    250.0,
    7.105427357601002e-15,
    800.0,
    8.000000000000007,
    fill="#EE5959",
    outline="")

canvas.create_rectangle(
    0.0,
    7.105427357601002e-15,
    250.0,
    600.0,
    fill="#222020",
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
    y=1.999999999999993,
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
    y=1.999999999999993,
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
    y=1.999999999999993,
    width=12.0,
    height=12.0
)

image_image_1 = PhotoImage(
    file=relative_to_assets("image_1.png"))
image_1 = canvas.create_image(
    318.0,
    35.00000000000001,
    image=image_image_1
)

image_image_2 = PhotoImage(
    file=relative_to_assets("image_2.png"))
image_2 = canvas.create_image(
    740.0,
    68.0,
    image=image_image_2
)

canvas.create_rectangle(
    278.0,
    166.0,
    618.0,
    506.0,
    fill="#EAEAEA",
    outline="")

entry_image_1 = PhotoImage(
    file=relative_to_assets("entry_1.png"))
entry_bg_1 = canvas.create_image(
    448.0,
    183.0,
    image=entry_image_1
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
window.resizable(False, False)
window.mainloop()
