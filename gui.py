import tkinter as tk
from tkinter import filedialog
import src
from src import script
import os

prop = script.preparation()
[working_directory, synthesis_dir, lib_dir, log_dir, test_dir] = prop["directories"]
config = prop["config"]

#---------------------------- Functions ---------------------
def gen_netlist():
    input_file_name = entry_fileName.get()
    module_name = entry_moduleName.get()
    script.netlist(input_file_name, module_name, config, working_directory, 
        synthesis_dir, lib_dir, log_dir,
        vhdl=tk_is_vhdl.get(), use_existing_script=tk_create_script.get())

    log_win.delete("1.0", tk.END)
    # read log file
    with open(os.path.join(log_dir, "yosys.log"), "r") as log_file:
        log_txt = log_file.read()
    
    log_win.insert(tk.END, log_txt)



# by the time that bench is executed the synthesis result must be ready
def gen_bench():
    script.bench(config, working_directory, 
        synthesis_dir, lib_dir, log_dir, test_dir)

    log_win.delete("1.0", tk.END)
    # read log file
    with open(os.path.join(log_dir, "abc.log"), "r") as log_file:
        log_txt = log_file.read()
    
    log_win.insert(tk.END, log_txt)
        

# by the time that fault is executed the synthesis result must be ready
def gen_fault():
    testbench_name = entry_testbench.get()
    dut_name = entry_dut_name.get()

    script.fault(testbench_name,  dut_name, config, working_directory, 
        synthesis_dir, lib_dir, log_dir, test_dir)

    log_win.delete("1.0", tk.END)
    # read log file
    with open(os.path.join(log_dir, "atalanta.log"), "r") as log_file:
        log_txt = log_file.read()
    
    log_win.insert(tk.END, log_txt)
        
# callback function for vhdl_checkbox
#   reserved for future use
def set_vhdl():
    pass

# callback function for create_script
#   reserved for future use
def set_create_script():
    pass

# callback function for open file dialog 
def openFile():
    file_dir = filedialog.askopenfilename(initialdir=working_directory, title="Select design")
    file_name = file_dir[file_dir.rfind('/') + 1:]
    entry_fileName.insert(0, file_name)

#----------------------------------------------------------------------- 

#---------------------------- Main window settings ---------------------
root = tk.Tk()
root.title('NBGen')

min_width = 800
min_height = 600

# get the screen dimension
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()

# find the center point
center_x = int(screen_width/2 - min_width / 2)
center_y = int(screen_height/2 - min_height / 2)

# set the position of the root to the center of the screen
root.geometry(f'{screen_width}x{screen_height}+{0}+{0}')
# window is resizable but has min/max constraint
# root.resizable(False, False)
# root.maxsize(min_height, max_height)
root.minsize(min_width, min_height)

root.rowconfigure([0, 1, 2], weight=1)
root.columnconfigure(0, weight=1)


#---------------------------- Set Variables ---------------------
if(os.path.exists("UT_png.png")):
    logo_file = tk.PhotoImage(file="UT_png.png")
else:
    logo_file = False
tk_is_vhdl = tk.BooleanVar(root, False)
tk_create_script = tk.BooleanVar(root, False)

#---------------------------- Frames ---------------------
fr_logo_title = tk.Frame(master=root)
fr_logo = tk.Frame(master=fr_logo_title)

fr_btns = tk.Frame(master=root)
fr_btn_genNetlist = tk.Frame(master=fr_btns, relief=tk.RAISED, borderwidth=1)
fr_btn_genBench = tk.Frame(master=fr_btns, relief=tk.RAISED, borderwidth=1)
fr_btn_genFault = tk.Frame(master=fr_btns, relief=tk.RAISED, borderwidth=1)
fr_btn_openFile = tk.Frame(master=fr_btns, relief=tk.RAISED, borderwidth=1)

fr_ent_label = tk.Frame(master=root, relief=tk.RAISED, borderwidth=1)
fr_entry = tk.Frame(master=fr_ent_label, relief=tk.RAISED, borderwidth=1)
fr_input_label = tk.Frame(master=fr_ent_label, relief=tk.RAISED, borderwidth=1)
fr_vhdl_checkbox = tk.Frame(master=fr_ent_label, relief=tk.RAISED, borderwidth=1)

fr_log_window = tk.Frame(master=root)
#-----------------------------------------------------------------------

#---------------------------- Create and Pack Widgets ---------------------
if(logo_file):
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

btn_genFault = tk.Button(
    master=fr_btn_genFault,
    text="Generate fault list & test vector",
    font=("Arial", 20),
    fg="red",
    command=gen_fault
)
btn_genFault.pack()

btn_openFile = tk.Button(
    master=fr_btn_openFile,
    text="Open file",
    font=("Arial", 20),
    fg="red",
    command=openFile
)
btn_openFile.pack()


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

entry_testbench = tk.Entry(
    master=fr_entry,
    fg="black", 
    bg="white", 
    width=25)
entry_testbench.pack()

entry_dut_name = tk.Entry(
    master=fr_entry,
    fg="black", 
    bg="white", 
    width=25)
entry_dut_name.pack()

checkbox_vhdl = tk.Checkbutton(
    master=fr_entry, 
    text='VHDL Design',
    variable=tk_is_vhdl,
    command=set_vhdl)
checkbox_vhdl.pack()

checkbox_create_script = tk.Checkbutton(
    master=fr_entry, 
    text='Use existing yosys script',
    variable=tk_create_script,
    command=set_create_script)
checkbox_create_script.pack()

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

fr_btns.grid(row=3, column=0)
fr_btn_genNetlist.grid(row=0, column=0)
fr_btn_genBench.grid(row=1, column=0)
fr_btn_genFault.grid(row=2, column=0)
fr_btn_openFile.grid(row=3, column=0)

fr_log_window.grid(row=4, column=0)
#-----------------------------------------------------------------------


#---------------------------- show README ---------------------
log_win.delete("1.0", tk.END)
if(os.path.exists("README.txt")):
    with open("README.txt", "r") as log_file:
        log_txt = log_file.read()
else:
    log_txt = "welcome to NBgen"

log_win.insert(tk.END, log_txt)
#-----------------------------------------------------------------------

# start main loop
root.mainloop()