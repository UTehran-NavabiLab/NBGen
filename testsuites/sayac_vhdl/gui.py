from doctest import master
import tkinter as tk
from tkinter.tix import Tree
import script
import os

prop = script.preparation()
[working_directory, synthesis_dir, lib_dir, log_dir, bench_dir] = prop["directories"]
config = prop["config"]

has_netlist = False
#---------------------------- Functions ---------------------
def gen_netlist():
    input_file_name = entry_fileName.get()
    module_name = entry_moduleName.get()
    script.netlist(input_file_name, module_name, config, working_directory, 
        synthesis_dir, lib_dir, log_dir, vhdl=tk_is_vhdl.get())

    log_win.delete("1.0", tk.END)
    # read log file
    with open(os.path.join(log_dir, "yosys.log"), "r") as log_file:
        log_txt = log_file.read()
    
    log_win.insert(tk.END, log_txt)
    global has_netlist
    has_netlist = True



def gen_bench():
    if (has_netlist):
        script.bench(config, working_directory, 
            synthesis_dir, lib_dir, log_dir, bench_dir)

        log_win.delete("1.0", tk.END)
        # read log file
        with open(os.path.join(log_dir, "abc.log"), "r") as log_file:
            log_txt = log_file.read()
        
        log_win.insert(tk.END, log_txt)
    else:
        log_txt = "netlist has not been generated yet \n"
        log_win.delete("1.0", tk.END)
        log_win.insert(tk.END, log_txt)
        
# callback function for vhdl_checkbox
#   reserved for future use
def set_vhdl():
    pass
#----------------------------------------------------------------------- 

window = tk.Tk()
window.rowconfigure([0, 1, 2], weight=1)
window.columnconfigure(0, weight=1)

logo_file = tk.PhotoImage(file="UT_png.png")
tk_is_vhdl = tk.BooleanVar(master, False)

#---------------------------- Frames ---------------------
fr_logo_title = tk.Frame(master=window)
fr_logo = tk.Frame(master=fr_logo_title)

fr_btns = tk.Frame(master=window)
fr_btn_genNetlist = tk.Frame(master=fr_btns, relief=tk.RAISED, borderwidth=1)
fr_btn_genBench = tk.Frame(master=fr_btns, relief=tk.RAISED, borderwidth=1)

fr_ent_label = tk.Frame(master=window, relief=tk.RAISED, borderwidth=1)
fr_entry = tk.Frame(master=fr_ent_label, relief=tk.RAISED, borderwidth=1)
fr_input_label = tk.Frame(master=fr_ent_label, relief=tk.RAISED, borderwidth=1)
fr_vhdl_checkbox = tk.Frame(master=fr_ent_label, relief=tk.RAISED, borderwidth=1)

fr_log_window = tk.Frame(master=window)
#---------------------------- Frames ---------------------
#-----------------------------------------------------------------------
logo = tk.Label(
    master=fr_logo,
    image=logo_file
).pack()

btn_genNetlist = tk.Button(
    master=fr_btn_genNetlist,
    text="Generate Netlist",
    font=("Arial", 20),
    fg="red",
    command=gen_netlist
)
btn_genNetlist.pack()

btn_genBench = tk.Button(
    master=fr_btn_genBench,
    text="Generate Bench",
    font=("Arial", 20),
    fg="red",
    command=gen_bench
)
btn_genBench.pack()


input_label = tk.Label(
    master=fr_input_label,
    text="Enter Module Name: ",
    fg="blue"
)
input_label.pack()

entry_fileName = tk.Entry(
    master=fr_entry,
    fg="black", 
    bg="white", 
    width=25)
entry_fileName.pack()

entry_moduleName = tk.Entry(
    master=fr_entry,
    fg="black", 
    bg="white", 
    width=25)
entry_moduleName.pack()

checkbox_vhdl = tk.Checkbutton(
    master=fr_entry, 
    text='VHDL Design',
    variable=tk_is_vhdl,
    command=set_vhdl)
checkbox_vhdl.pack()

log_win = tk.Text(
    master=fr_log_window,
)
log_win.pack()

#---------------------------- Manage Geometry ---------------------
fr_logo_title.grid(row=0, column=0)
fr_logo.grid(row=0, column=0)

fr_ent_label.grid(row=2, column=0, pady=40)
fr_input_label.grid(row=0, column=0)
fr_entry.grid(row=1, column=0)

fr_btns.grid(row=3, column=0, pady=40)
fr_btn_genNetlist.grid(row=0, column=0)
fr_btn_genBench.grid(row=1, column=0)

fr_log_window.grid(row=4, column=0)
#-----------------------------------------------------------------------


#---------------------------- show README ---------------------
log_win.delete("1.0", tk.END)
with open("README.txt", "r") as log_file:
    log_txt = log_file.read()

log_win.insert(tk.END, log_txt)
#-----------------------------------------------------------------------

# start main loop
window.mainloop()