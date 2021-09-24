import json, requests

url = '<url>'


# Start API 키 발급 (한 번 실행 후 주석처리)
# auth_key 저장해서 사용 !
def start():
    headers = {
        'X-Auth-Token': '<token>',
        'Content-Type': 'application/json',
    }
    data = '{ "problem": 1 }'

    response = requests.post(url + '/start', headers=headers, data=data).json()
    print(response)

    auth_key = response['auth_key']
    print(auth_key)

    return auth_key


key = start()


headers = {
    'Authorization': key,
    'Content-Type': 'application/json',
}

lc = [0 for i in range(25)]
trucks = [0 for i in range(5)]


# locations 읽기
def getLocation():
    locations = requests.get(url + '/locations', headers=headers).json()['locations']

    # 편하게 사용하기 위해 리스트로 복사
    for i in range(0, 25):
        lc[i] = locations[i]['located_bikes_count']


# trucks 읽기
def getTrucks():
    tr = requests.get(url + '/trucks', headers=headers).json()['trucks']

    for i in range(0, 5):
        trucks[i] = tr[i]


# 트럭 옮기기
def move(line_id):
    """
    <단순 알고리즘>
    1. 각 라인별로 트럭 1대씩 배치
    2. 3이하 -> 아래로 출발, 3초과 -> 위로 출발
    3. 바이크의 개수에 따라 싣거나 놓는다.
    :param line_id: 각 라인 (열 기준)
    :return: 트럭의 움직임이 담긴 command 리스트
    """
    command = []

    # 현재 트럭의 위치
    truck_id = trucks[line_id]['location_id']

    # 세로 행 자리 지정
    dis = int(truck_id / 5) - line_id
    if dis > 0:  # 우측 행에 있을 떄
        for di in range(dis):
            command.append(4)
            truck_id -= 5
    elif dis < 0:  # 좌측 행에 있을 때
        dis = dis*-1

        for di in range(dis):
            command.append(2)
            truck_id += 5

    bound_down = line_id * 5
    bound_up = bound_down + 5
    bike_cnt = trucks[line_id]['loaded_bikes_count']

    if truck_id%5 > 3:
        truck_dir = 1  # 위로
    else:
        truck_dir = 3  # 아래로

    while len(command) <= 10:
        if truck_dir == 1:
            truck_id += 1
            if truck_id >= bound_up:
                truck_id -= 1
                truck_dir = 3
                continue
        else:
            truck_id -= 1
            if truck_id < bound_down:
                truck_id += 1
                truck_dir = 1
                continue

        command.append(truck_dir)

        if lc[truck_id] > 3:
            command.append(5)
            bike_cnt += 1
        else:
            if bike_cnt > 0:
                command.append(6)
                bike_cnt -= 1
                if lc[truck_id] < 2 and bike_cnt > 1:
                    command.append(6)
                    bike_cnt -= 1

    command = command[:10]  # 10개만 남기기
    return command


def simulate():
    data = json.dumps({"commands": commands})
    # simulate API
    res = requests.put(url + '/simulate', headers=headers, data=data).json()
    print(res)


# 720번 실행
for j in range(720):
    getLocation()
    getTrucks()

    # commands 저장
    commands = []
    for i in range(5):
        d = dict()
        d["truck_id"] = i
        d["command"] = move(i)
        commands.append(d)

    simulate()


# print Result
result = requests.get(url + '/score', headers=headers).json()
print(result)
