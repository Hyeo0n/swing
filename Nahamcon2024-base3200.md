<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <h1>Nahamcon 2024 CTF- Base3200 Write-UP</h1>
</body>
<br>
<br>
</html>

다른 문제들과는 다르게, 이 문제는 이름이 Base 3200이라서, 그냥 암호화된 것을 디코딩만 해내면, flag를 쉽게 얻을 수 있지 않을까 하여 선택하였다. 

![image](https://github.com/Hyeo0n/swing/assets/163324653/e4a8ef26-c7e3-41e9-ac07-4136ee7633e6)

일단 문제 설명대로, theflag.xz 파일을 다운받고, 압축 해제하였다. 
그리고 이 파일을 메모장으로 연결해서 열어본 결과, 

![image](https://github.com/Hyeo0n/swing/assets/163324653/5ae6a30b-cf9e-422b-bd9e-d46249265ed0)

이런 형식으로 79918301자나 되는 엄청 긴 알 수없는 문자열이 있었다. 뭔가 이 문자열이 암호화된 것 같아서 이를 디코딩하면 flag를 얻을 수 있을 것 같았다.
근데 여기서 막혔던 부분은 base 인코딩 방식 중 64, 32와 같은 방식들만 있지, base 3200이라는 방식은 없는 것이었다. 그래서 base3200에 대해서 열심히 서칭해본 결과

![image](https://github.com/Hyeo0n/swing/assets/163324653/daac2f70-2bcb-426d-ac51-1af2919a66ae)

base3200이 bas64 방식을 50번 반복한 것이라고 디코딩하는 것을 발견하였다. 그래서, 이 파일을 전달받아서, base64 방식으로 디코딩을 50번 진행하는 코드를 작성하여, 
flag값을 얻어보려고 한다. 어떤 프로그램 언어로 작성해야될까 고민하였는데, 최근에 SSR 작성하면서, 다른 인코딩 방식이긴 하지만, 자바스크립트로 암호화된 문자열을 디코딩하는 코드를 작성했던 것이 떠올라서
지난번에 쓴 SSR을 참고하여, 자바스크립트로 작성해보려고 한다.

<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <h2>코드 작성</h2>
</body>
<br>
<br>
</html>

![image](https://github.com/Hyeo0n/swing/assets/163324653/73004d62-12bc-4af9-b7d1-d68c917b1c0f)

내가 작성한 코드는 위와 같다. 일단 먼저 압축해제된 theflag 파일을 전달받아야 하기 때문에, fs 모듈을 사용하려고 한다. Node.js에서는 fs(file system)모듈을 불러와야지, 파일과 
관련된 전반적인 처리를 할 수 있다고 하여, fs 모듈을 불러왔다. const fs = require('fs'); 를 통해, fs모듈을 먼저 불러오는 코드를 작성하였다. 그리고,
base64Decode라는 함수를 새롭게 선언하였고, 이 함수는 Base64로 인코딩된 문자열을 받아서 UTF-8로 디코딩한 후 반환하게 작성하였다.
함수 내부에서는 Buffer.from() 메서드로, Base64로 인코딩된 데이터를 저장한 새로운 버퍼를 만들고, 이 데이터를 toString('utf-8')을 사용하여 UTF-8 문자열로 변환시킨다. 
그리고, fs.readFile() 함수를 사용하여 "theflag" 파일을 전달받아 UTF-8 형식으로 읽게 만든다. 그리고, 파일을 읽은 후에 실행시킬 명령을 지정하기 위해 콜백함수를 만들고, 
파일을 읽은 후에는 콜백 함수가 호출됩니다. 이 콜백 함수는 err과 data라는 두 개의 인자를 전달받도록 한다. err은 에러가 발생한 경우에 사용되고, data는 파일 내용을 포함하는 인자이다. 
에러가 발생하면, Error reading file라는 메시지를 출력하고 함수를 종료시킨다. 아까 toString으로 문자열로 반환된 파일 내용은 문자열로 data 변수에 저장됩니다. 
문자열의 앞뒤 공백을 제거하는 trim()함수를 사용하여, data에 저장된 문자열을 앞뒤 공백을 제거하고, 이를 새로운 변수 d에 저장한다.
그 후, 반복문을 사용하여 문자열을 50번 반복하면서, 각 반복마다 base64Decode() 함수를 호출하여 Base64 디코딩을 수행하게끔 한다. 
그리고 이를, 다시 변수 d에 저장하고, 이를 출력하게끔 코드를 작성해보았다.  

<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <h2>flag 찾기</h2>
</body>
<br>
<br>
</html>

위에서 작성한 코드를 Node.js로 실행해보았다.

![image](https://github.com/Hyeo0n/swing/assets/163324653/8339ddf8-e2fb-4297-a9f9-4169aeedf443)

flag값이 flag{340ff1bee05244546c91dea53fba7642} 로 출력되는 것을 확인할 수 있다!

이 flag값을 실제로 입력해보니, 

![image](https://github.com/Hyeo0n/swing/assets/163324653/5b5c9807-3435-46e0-bd91-37dea459124a)

![image](https://github.com/Hyeo0n/swing/assets/163324653/19eb9203-fd25-4010-a2d6-a60d19d00496)

문제를 해결할 수 있었다!
