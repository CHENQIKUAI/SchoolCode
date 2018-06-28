var p, q, L, E, D;
var sA, sB;
function getE(L) {
    for (var i = 2; i < L; ++i) {
        if (gcd(L, i) == 1) {
            return i;
        }
    }
    return;
}

function lcm(a, b) {
    return a * b / gcd(a, b);
}

function gcd(a, b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

function inverseElement(K, N) {
    for (var i = 0; i < N; ++i) {
        if ((i * N + 1) % K == 0) {
            return (i * N + 1) / K;
        }
    }
    return -1000;
}

function getD(E, L) {
    return inverseElement(E, L);
}

function encrypt(Plaintext) {
    return rsaEncrypt(Plaintext);
}

function decrypt(ciphertext) {
    return rsaDecrypt(ciphertext);
}

//rsa ecyptology
function rsaEncrypt(iNum) {

    var temp = 1;
    for (var i = 1; i <= E; i++) {
        temp = temp * iNum;
        temp = temp % N;
    }
    return temp;
}

function rsaDecrypt(iNum) {

    var temp = 1;
    for (var i = 1; i <= D; i++) {
        temp = temp * iNum;
        temp = temp % N;
    }
    return temp;
}

function exactEncrypt(str) {
    var temp = '';
    for (var i = 0; i < str.length; ++i) {
        var codeAt = str[i].codePointAt();
        console.log('code:' + codeAt);
        var encryptCode = encrypt(codeAt);
        console.log('encryptCode:' + encryptCode);
        temp += String.fromCodePoint(encryptCode);
    }
    sB = temp;
    return temp;
}

function exactDecrypt(str) {
    var temp = '';
    for (var i = 0; i < str.length; ++i) {
        var codeAt = str[i].codePointAt();
        console.log(codeAt);
        var encryptCode = decrypt(codeAt);
        temp += String.fromCodePoint(encryptCode);
    }
    sA = temp;
    return temp;
}


$('form').submit(function(event) {
    p = $('#p:text').val();
    q = $('#q:text').val();
    //No.1 get N
    N = p * q;
    //No.2 get L
    L = lcm(p - 1, q - 1);
    //No.3 get E
    E = getE(L);
    //No.4 get D
    D = getD(E, L);


    $('.result-E').text(E);
    $('.result-D').text(D);
    $('.result-N').text(N);

    $('.footer').css('display', 'block');

    return false;
});


$('.encrypt').click(function() {
    var Plaintext = $('#m').val();
    var ciphertext = exactEncrypt(Plaintext);
    console.log(ciphertext);

    $("#mm").val(ciphertext);
});


$('.decrypt').click(function() {
    var ciphertext = $('#mm').val();
    var Plaintext = exactDecrypt(ciphertext);
    console.log(Plaintext);

    $("#m").val(Plaintext);
});

function copy(txt) {
    var oInput = document.createElement('input');
    oInput.value = txt;
    document.body.appendChild(oInput);
    oInput.select(); // 选择对象
    document.execCommand("Copy"); // 执行浏览器复制命令
    oInput.className = 'oInput';
    oInput.style.display = 'none';
    alert('复制成功');
}

$('.copy1').click(function() {
    var txt = $('#m').val();
    copy(txt);
});


$('.copy2').click(function() {
    var txt = $('#mm').val();
    copy(txt);
});

function jsReadFiles(files) {
    if (files.length) {
        var file = files[0];
        var reader = new FileReader(); //new一个FileReader实例
        if (/text+/.test(file.type)) { //判断文件类型，是不是text类型
            reader.onload = function() {
                $('#m').val(this.result);
            }
            reader.readAsText(file);
            $(this).val("");
        }
    }
}

function jsReadFiles2(files) {
    if (files.length) {
        var file = files[0];
        var reader = new FileReader(); //new一个FileReader实例
        if (/text+/.test(file.type)) { //判断文件类型，是不是text类型
            reader.onload = function() {
                $('#mm').val(this.result);
            }
            reader.readAsText(file);
        }
    }
}