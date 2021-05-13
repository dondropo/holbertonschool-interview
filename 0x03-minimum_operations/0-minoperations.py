#!/usr/bin/python3
""" minimun operations, returns int """


def minOperations(n):
    """ minimum operations """

    if (n <= 1):
        return 0

    hs = 1
    processCount = 0
    copypaste = 0

    while (hs < n):
        if (n % hs == 0):
            processCount += 2
            copypaste = hs
        else:
            processCount += 1

        hs = copypaste + hs

    return processCount
