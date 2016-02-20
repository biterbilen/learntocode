import sys


def analyze(days, teams, costs):
    min_value = sys.float_info.max

    for schedule in range(teams, days):
        for s in range(days - schedule):
            e = s + schedule
            cost = (sum(costs[s:e]) / float(schedule))

            if cost < min_value:
                min_value = cost

    return min_value

if __name__ == '__main__':
    count = int(raw_input())

    for _ in range(count):
	days, teams = map(int, raw_input().split())
	costs = list(map(int, raw_input().split()))

	print(analyze(days, teams, costs))
