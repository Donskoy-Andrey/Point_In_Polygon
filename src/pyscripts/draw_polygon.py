import sys
import matplotlib.pyplot as plt


def draw(xs: list, ys: list, x: float, y: float, path: str, text: str) -> None:
    plt.figure(figsize=(8, 8))
    plt.title(text, fontsize=20)
    plt.fill(xs, ys, c='yellow', alpha=0.3)
    plt.scatter(xs, ys, c='b')
    plt.scatter(x, y, c='r')
    plt.legend(['polygon', 'vertex', 'our point'])
    plt.savefig(f'../data/images/{path}.png')


def main():
    path = sys.argv[1]
    point_x, point_y = float(sys.argv[2]), float(sys.argv[3])
    text = int(sys.argv[4])
    if (text == -1):
        text = "On the Edge"
    elif (text == 0):
        text = "Inside of the Polygon"
    else: 
        text = "Outside of the Polygon"
    xs = []
    ys = []
    with open(path, 'r') as file:
        for line in file.readlines():
            x, y = line.split()
            xs.append(float(x))
            ys.append(float(y))
    path = path.split('/')[-1].split('.')[0]
    draw(xs, ys, point_x, point_y, path, text)


if __name__ == "__main__":
    main()