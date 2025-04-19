#target: 1 2 3 2 1
#layers:
#        1 1 1 1 1      <- lớp 1
#        0 1 1 1 0      <- lớp 2
#        0 0 1 0 0      <- lớp 3
#Mỗi lớp là một thao tác, và tổng số lớp chính là số lần tăng cần thiết.
#Bạn có thể thấy rằng:
#Chỗ nào bắt đầu tăng, tức là target[i] > target[i-1] → cần thêm thao tác mới.


def min_operations(target):
    steps = target[0]
    for i in range(1, len(target)):
        if target[i] > target[i - 1]:
            steps += target[i] - target[i - 1]
    
    return steps


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        target = list(map(int, input().split()))
        print(min_operations(target))
        #print()
