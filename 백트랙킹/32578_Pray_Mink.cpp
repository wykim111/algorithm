/*
    <백트래킹 - 재귀>

    1. 에라스토테네스의 체로 소수를 구함.(10^9까지)
    2. 입력된 수의 부분집합을 구함
    3. 탐색
        go(dep, num_str, int prime_cnt)
        {
            if(num_str이 ""이 되면 소수)
            {

                return;
            }

            if(num_str이 소수라면) -> map 사용해서 중복 제거
            {
                prime_cnt++;
            }
            else // 소수가 아니라면
            {
                return;
            }

            for(int i = 0; i < num_str.size(); i++)
            {
                char c = num_str[i];

                num_str에서 i번쨰 숫자 지움
                go(dep + 1, num_str, prime_cnt);
                num_str에서 i번쨰 숫자 다시 넣음
            }


        }
    4. 결과 출력

*/
