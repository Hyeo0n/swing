<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <h1>5월 DreamHack CTF Season 5 Round #10 pharamacy Write-UP</h1>
</body>
<br>
<br>
</html>



지금 다룰 CTF 문제는 DreamHack CTF Season 5 Round #10인 pharamacy 문제이다. 최근에 관심을 가지고 공부하는 웹 부분이라서,
한 번 도전해보고 싶어서 이 문제를 선택했다. 이번에 웹 부분이 어렵게 출제된 것 같지만, 끝까지 열심히 풀어보고 싶다.


![image](https://github.com/Hyeo0n/swing/assets/163324653/0a853ece-293c-4cd2-bb01-7ffbfccfce91)


문제 설명을 보면, " When things were wild, there was a good, old pharmacy... with a supermarket? " 라고 되어있는데,
사실 무슨 말인지 감이 잘 안 와서, 그냥 pharmacy가 좋으니까, pharmacy 부분을 유심히 봐야겠다고 생각했다.


![image](https://github.com/Hyeo0n/swing/assets/163324653/cfc6015c-711f-4958-9361-570522247702)

![image](https://github.com/Hyeo0n/swing/assets/163324653/be24a10e-28d7-4b7d-80dd-7e1a393849ad)

![image](https://github.com/Hyeo0n/swing/assets/163324653/d05d4ed2-78a0-4e5e-8a9f-066ecc0be509)


문제 파일을 다운받으니, 되게 많은 파일들이 있었다. 일단 이 파일 하나하나 열어서, 코드를 읽어보면서
, 어떻게 문제를 풀어야 할지 방향성을 잡아야 겠다고 생각했다.


<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <h2>DockerFile</h2>
</body>
<br>
<br>
</html>
  
![image](https://github.com/Hyeo0n/swing/assets/163324653/d0b26092-d24b-4f76-88f9-6f626c4afd4d)


도커파일을 열어보니, 위와 같은 코드를 확인할 수 있었다. 
COPY ./deploy/run.sh /usr/sbin/ 이 코드는 ./deploy/run.sh 스크립트를 Docker 이미지의 /usr/sbin/ 디렉토리로 복사한다는 것 같았고, 
RUN chmod +x /usr/sbin/run.sh 이 코드는 위에서 복사한 run.sh 스크립트에 실행 권한을 부여하는 코드로 보였다.
뒤이어 COPY ./deploy/src /var/www/html 이 코드는 ./deploy/src 디렉토리에 있는 파일들을 Docker 이미지의 /var/www/html 디렉토리로 복사하는 것으로 보인다. 
RUN chmod 777 /var/www/html/uploads 이 코드는 위에서 복사한 /var/www/html/uploads 디렉토리에 모든 사용자에게 읽기, 쓰기, 실행 권한을 부여하는 것으로 보인다.
뒤에, COPY ./deploy/flag.txt / 이 코드는 ./deploy/flag.txt 파일을 Docker 이미지의 루트 디렉토리 (/)로 복사하는 코드인 것 같다. 
그 후, CMD ["/usr/sbin/run.sh"] 코드는 컨테이너가 시작될 때 /usr/sbin/run.sh 스크립트를 실행하게끔 만든 코드같다.
대략적으로 이 파일은 컨테이너 시작 시 필요한 초기 설정 또는 서버 실행을 다루고 있는 파일같은데, 문제를 푸는데 앞서, 뭔가 엄청 중요해 보이지는 않는 것 같다.


<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <h2>flag.txt</h2>
</body>
<br>
<br>
</html>

이 파일에는 별다른 코드는 없었고,placeholder이라는 말 한 마디만 저장되어 있었다. 
placeholder는 문자나 이미지 등의 요소가 들어갈 자리에 임시로 채워놓는 내용물을 말하는데, 아직 내용이 정해지지 않았거나 내용이 가변적인 경우 
임시로 내용이 들어가는 부분이므로, 뭔가 나중에 이 자리에 어떤 문서나 파일이 들어가지 않을까 생각했다.


<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <h2>run.sh</h2>
</body>
<br>
<br>
</html>

![image](https://github.com/Hyeo0n/swing/assets/163324653/2338fd8b-48ae-417a-9ef8-1bc52a94a2c0)

쉘 스크립트 부분을 열어봤는데, 별다른 코드는 많이 없고
보니까, export FLAG="test" 이 코드는 FLAG라는 변수를 선언하고, 그 값을 "test"로 초기화한 것 같다.

<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <h2>index.php</h2>
</body>
<br>
<br>
</html>

![image](https://github.com/Hyeo0n/swing/assets/163324653/37bbb455-eaaa-4ed9-beba-90550bfb6ee2)


![image](https://github.com/Hyeo0n/swing/assets/163324653/d402268f-8b97-41e3-9d6f-df74a3910124)

index 파일을 열어보니까, php 형식과 html 형식이 섞여있는 것 같았다. 
HTML 부분만 뜯어서 보면,

![image](https://github.com/Hyeo0n/swing/assets/163324653/a4e00b20-b513-4f1e-a2fe-eb72ab7a140c)

이런 형식인데, 코드를 보니까, prescription 처방전을 업로드하게 하는 웹 페이지를 만드는 코드같다. input 명령어로 파일 형식을 받는 것을 보니
, 사용자가 처방전 파일을 업로드하고 이를 입력받는 형식으로 웹 페이지가 구성되는 것 같다. 실제로 이 파일을 HTML 확장자로 바꿔서 웹 브라우저에서 실행시켜 보니, 

![image](https://github.com/Hyeo0n/swing/assets/163324653/4c5762ff-50c4-43a2-9158-a13fced2e541)


위와 같은 형식으로 처방전을 입력받는 웹 페이지가 나오는 것을 확인할 수 있었다. PHP 부분을 살펴보면,


![image](https://github.com/Hyeo0n/swing/assets/163324653/673fd7dd-549e-487e-83f2-d07ecb1b28b8)


이런 형식으로 구성되어 있다. 
<?php require("supermarket.php"); ?> 이 부분을 보니, supermarket.php 파일에서 필요한 기능이나 설정을 가져오는 코드같았다. 
if( isset($_POST["submit"])) 문을 살펴보면, 처방전 파일이 입력되면, 업로드된 파일의 이름을 얻고, pathinfo라는 말을 보니, 파일의 경로를 가져오는 건가 생각했다.
또한, fileExtension 이라는 말을 보니, 파일 확장자 또한 가져오는 건가 라고 생각했다. 
그 밑에,  if (mime_content_type($tmpFile) !== "image/gif" || $fileExtension !== "gif") 문을 보니,
파일 확장자명이 gif이 아니면, Prescription not gif! 처방전이 gif 형식이 아니라는 말을 출력하고, 맨처음에 1로 초기화된 uploadOK가 0으로 저장되는 코드같다. 
그 밑에,  if ($uploadOK == 0) 과 else 문을 보니, uploadOK가 0이면 Prescription upload failed. 처방전 업로드를 실패했다는 문구를 출력하고,
만약 uploadOK 가 1이면, 업로드 된 파일이 존재하는지 확인하여서, 처방전이 제출되었다는 문구나 처방전 업로드가 실패했다는 문구를 출력하는 코드 같다. 
맨 처음에 문제 설명에서  pharmacy with a supermarket 이라고 말했는데, supermarket 부분이 중요한 부분 같아 바로 supermarket.php 파일을 살펴봐야 겠다.

<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <h2>supermarket.php</h2>
</body>
<br>
<br>
</html>

![image](https://github.com/Hyeo0n/swing/assets/163324653/27e76f6c-5bce-47f2-a0e6-bce0aa32e9b3)

이 코드를 보니,
function goodbye($customer) { echo "Good bye, $customer!\n"; } 이 부분은, goodbye라는 함수가, customer이라는 인수를 전달받고, 고객이름과 함께 잘가라는 문구를 출력하는 함수를 정의한 것 같다
class Supermarket을 살펴보니, $greet는 'goodbye' 문자열을 가지고, $customer은 'dream' 문자열을 가지는 것 같다. __destruct이라는 함수는 보기에 뭔가 소멸자 함수 같은데, 
$greet에 저장된 것을 호출하고, $customer에 저장된 것을 호출하는 것 같았다. 그래서, 결과적으로 객체가 소멸될 때마다 "Good bye, dream!"이라는 메시지가 출력되는 거지 않을까 생각했다.


<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <h2>마무리</h2>
</body>
<br>
<br>
</html>

대략적으로 파일들을 다 훑어보면서, 파악해보았다. flag를 flag.txt에서 확인할 수 있다고 했는데, 뭔가 이를 얻기 위해서는 pharamacy 부분이 중요해보이는데, 이 pharamacy에서 어떤 파일을 업로드해야될지 감이 안 잡힌다. gif 확장자명을 가진 파일을 업로드해야될 것 같은데, 어떤 파일을 어떻게 업로드해야될지 감이 안 잡힌다. 
후에 다른 사람들의 라이트업을 참고해서, 다시 방향성을 잡고 문제를 풀어봐야 겠다는 생각이 들었다. 
