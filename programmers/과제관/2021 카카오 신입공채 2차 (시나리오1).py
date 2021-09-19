import json, requests

url = '<url>'

# Start API 키 발급 (한 번 실행 후 주석처리)
# auth_key 저장해서 사용 !
headers = {
    'X-Auth-Token': '<token>',
    'Content-Type': 'application/json',
}

data = '{ "problem": 1 }'

response = requests.post(url+'/start', headers=headers, data=data).json()
print(response)

auth_key = response['auth_key']
print(auth_key)

# auth_key 설정
key = auth_key

# locations 읽기
headers = {
    'Authorization': key,
    'Content-Type': 'application/json',
}

locations = requests.get(url + '/locations', headers=headers).json()['locations']

# 편하게 사용하기 위해 리스트로 복사
lc = []
for i in range(0, 25):
    lc.append(locations[i]['located_bikes_count'])
print(lc)

# trucks 읽기
trucks = requests.get(url + '/trucks', headers=headers).json()['trucks']
# print(len(trucks))  # 리스트의 개수

# for i in trucks:  # for-each 해봤다.
# #     print(i)


# #############################################################
# #################### 알고리즘 구현 #############################

def move(line_id):
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

    truck_dir = 0
    if truck_id%5 > 3:
        truck_dir = 1 #위로
    else:
        truck_dir = 3 #아래로

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


# #############################################################

# commands 저장
for j in range(720):
    locations = requests.get(url + '/locations', headers=headers).json()['locations']
    for il in range(25):
        lc[il] = locations[i]['located_bikes_count']

    trucks = requests.get(url + '/trucks', headers=headers).json()['trucks']

    commands = []
    for i in range(5):
        d = dict()
        d["truck_id"] = i
        d["command"] = move(i)
        commands.append(d)

    # json
    data = {
        "commands": commands
    }
    
    data = json.dumps(data)
    

    # simulate API
    res = requests.put(url + '/simulate', headers=headers, data=data).json()
    # print(j)
    # print(res)

    
# print Result
result = requests.get(url + '/score', headers=headers).json()
print(result)
