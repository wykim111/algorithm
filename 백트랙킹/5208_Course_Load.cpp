/*
    < 백트래킹 - subset>

    1. 탐색
        go(dep, int utility_sum, int work_sum)
        {
            if(dep == 모든 과목 수)
            {
                //최대 효용 업데이트

                return;
            }

            // dep번째 과목을 선택하는 경우
            if(현재 과목을 선택하는 조건에 만족하는 경우)
            {
                cur_utility = 현재 과목의 효용
                cur_work = 현재 과목의 작업량
                
                //현재 선택한 과목에 대해 시간 체크
                go(dep+1, utility_sum + cur_utility, work_sum + cur_work);
                //현재 선택한 과목에 대해 시간 체크 해제
            }

            // dep번째 과목을 선택하지 않은 경우
            go(dep+1, utility_sum, work_sum);
        }
    2. 현재 과목을 선택하는 조건에 만족하지 않은 경우 제외해야 함.
        2-1. 내 시간대와 벗어나는 과목은 제외
        2-2. 내 시간대와 겹치는 과목은 제외
        2-3. 내 작업량을 초과하는 과목은 제외

*/