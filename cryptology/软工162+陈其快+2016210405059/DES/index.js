$('.encrypt').click(function () {
    var Plaintext = $('#m').val();
    var ciphertext = e_des(Plaintext);
    $("#mm").val(ciphertext);
});

$('.decrypt').click(function () {
    var ciphertext = $('#mm').val();
    var Plaintext = d_des(ciphertext);
    $("#m").val(Plaintext);
});


function e_des(str) {
    var key1=$('.key1').val();
    var key2=$('.key2').val();
    var key3=$('.key3').val();
    var enResult=strEnc(str,key1,key2,key3);
    return enResult;
}
function d_des(str) {
    var key1=$('.key1').val();
    var key2=$('.key2').val();
    var key3=$('.key3').val();
    var deResult = strDec(str,key1,key2,key3);
    return deResult;
}



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


$('.copy1').click(function () {
    var txt = $('#m').val();
    copy(txt);
});


$('.copy2').click(function () {
    var txt = $('#mm').val();
    copy(txt);
});


function jsReadFiles(files) {
    if (files.length) {
        var file = files[0];
        var reader = new FileReader(); //new一个FileReader实例
        if (/text+/.test(file.type)) { //判断文件类型，是不是text类型
            reader.onload = function () {
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
            reader.onload = function () {
                $('#mm').val(this.result);
            }
            reader.readAsText(file);
        }
    }
}