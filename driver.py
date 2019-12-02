import mimirpywrapper.mimir_py_wrapper as mimirwrap


def main():
    print("Test driver for Mimir Backend Library and Wrapper")
    x = mimirwrap.trajectorymodel()

    x.fill_data(10)
    print("Length of x is {}".format(x.len_x_positions()))
    for i in range(0, x.len_x_positions()):
        print(x.get_x_positions(i), x.get_y_positions(i))


if __name__ == "__main__":
    main()
