def activitySelection(a, N):
    # Sort the activities according to their finish time
    a.sort(key = lambda x: x[1])

    # The first activity is always selected
    selectCount = 0
    startTimes = 0

    for i in range(N):
        if a[i][0] >= startTimes:
            selectCount += 1
            startTimes = a[i][1]
        
    return selectCount

# Driver code
if __name__ == "__main__":
    a = [[1, 2], [3, 4], [0, 6], [5, 7], [8, 9], [5, 9]]
    N = len(a)
    print(activitySelection(a, N))
    assert activitySelection(a, N) == 4