import tkinter as tk
from graph import Graph
from dijkstra import dijkstra, get_path
import random

graph = Graph()
edges = [
    ("A", "B", 5),
    ("A", "C", 2),
    ("B", "C", 3),
    ("B", "D", 4),
    ("C", "D", 6)
]
for u, v, w in edges:
    graph.add_edge(u, v, w)
positions = {
    "A": (120, 100),
    "B": (320, 100),
    "C": (200, 260),
    "D": (420, 260)
}
#GUI
root = tk.Tk()
root.title("Network Routing Simulator")
root.geometry("900x500")
root.configure(bg="#1e1e1e")
# LEFT
canvas = tk.Canvas(root, width=600, height=500, bg="#252526", highlightthickness=0)
canvas.pack(side="left", fill="both")
# RIGHT
panel = tk.Frame(root, bg="#1e1e1e", padx=20, pady=20)
panel.pack(side="right", fill="y")

def draw_graph(path=None):
    canvas.delete("all")
    drawn = set()
    for u in graph.nodes:
        x1, y1 = positions[u]
        for v in graph.nodes[u]:
            w = graph.get_weight(u,v)
            if (u, v) in drawn or (v,u) in drawn:
                continue
            x2,y2 = positions[v]
            color= "#555"
            width =2
            if path and u in path and v in path:
                if abs(path.index(u)-path.index(v))==1:
                    color = "#4CAF50"
                    width = 4
            canvas.create_line(x1, y1, x2, y2, fill=color, width=width)
            mx, my = (x1 + x2)//2, (y1 + y2)//2
            canvas.create_text(mx, my, text=str(w), fill="white", font=("Arial", 10))
            drawn.add((u, v))
    for node, (x, y) in positions.items():
        canvas.create_oval(x-25, y-25, x+25, y+25, fill="#007acc", outline="")
        canvas.create_text(x, y, text=node, fill="white", font=("Arial", 12, "bold"))
def styled_label(text):
    return tk.Label(panel, text=text, bg="#1e1e1e", fg="white", font=("Segoe UI", 11))
def styled_button(text, cmd, color="#007acc"):
    return tk.Button(
        panel,
        text=text,
        command=cmd,
        bg=color,
        fg="white",
        activebackground="#005f99",
        relief="flat",
        padx=10,
        pady=5,
        font=("Segoe UI", 10, "bold"),
        cursor="hand2"
    )
start_var = tk.StringVar(value="A")
end_var = tk.StringVar(value="D")
styled_label("Start Node").pack(anchor="w")
tk.Entry(panel, textvariable=start_var, width=10).pack(pady=5)
styled_label("End Node").pack(anchor="w")
tk.Entry(panel, textvariable=end_var, width=10).pack(pady=5)
result_label = tk.Label(panel, text="", bg="#1e1e1e", fg="#4CAF50", font=("Segoe UI", 11))
result_label.pack(pady=10)

def find_path():
    start = start_var.get()
    end = end_var.get()
    distances, previous = dijkstra(graph, start)
    path = get_path(previous, start, end)
    if not path:
        result_label.config(text="No Path Found", fg="red")
        draw_graph()
        return
    cost = distances[end]
    result_label.config(text=f"Path: {' → '.join(path)}\nCost: {cost}")
    draw_graph(path)
    animate_packet(path)

def simulate_traffic():
    for (u,v) in graph.edges:
        new_weight = random.randint(3, 15)
        graph.set_weight(u,v,new_weight)
    result_label.config(text="Traffic Updated", fg="#ffaa00")
    draw_graph()

def animate_packet(path):
    if len(path)<2:
        return
    radius=6
    speed=20  
    def move_segment(i):
        if i>=len(path)-1:
            return
        x1,y1=positions[path[i]]
        x2,y2=positions[path[i+1]]
        steps=30
        dx=(x2-x1)/steps
        dy=(y2-y1)/steps
        packet=canvas.create_oval(
            x1-radius,y1-radius,
            x1+radius,y1+radius,
            fill="#ffeb3b",outline=""
        )
        def animate_step(step):
            if step>=steps:
                canvas.delete(packet)
                move_segment(i + 1)
                return
            canvas.move(packet, dx, dy)
            root.after(speed,lambda: animate_step(step + 1))
        animate_step(0)
    move_segment(0)

styled_button("Find Path",find_path).pack(fill="x",pady=10)
styled_button("Simulate Traffic", simulate_traffic, "#ff9800").pack(fill="x")

draw_graph()
root.mainloop()