# This is a sample Python script.

# Press Umschalt+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
arr_sum = []
arr = []
def print_hi(name):
        for i in range(1, 1000000000000):
            for j in range(1,i):
                for k in range(1, j):
                    print(i, j, k);





# Press the green button in the gutter to run the script.
if __name__ == '__main__':

    from multiprocessing.dummy import Pool as ThreadPool

    # Make the Pool of workers
    pool = ThreadPool(12)

    # Open the URLs in their own threads
    # and return the results
    results = pool.map(print_hi, "1")
    #run the prozess with 12 workers


    # Close the pool and wait for the work to finish
    pool.close()
    pool.join()


# See PyCharm help at https://www.jetbrains.com/help/pycharm/
