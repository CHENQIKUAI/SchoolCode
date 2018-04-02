var count = 0;
function chToRed(argument) {
	var oneone = document.getElementById('oneone');
	oneone.bgColor = 'red';

}

function beDate(argument) {
	var onetwo = document.getElementById('onetwo');

	var today = new Date();
	var y = today.getFullYear();
	var m = today.getMonth();
	var d = today.getDate();
	var total = y + '-' + m + '-' + d;
	onetwo.innerHTML = total;
}

function addRow(argument) {
	var tr = document.createElement("tr");
	tr.id = "other" + count;
	var td1 = document.createElement("td");
	var td2 = document.createElement("td");
	var text = document.createTextNode("annother line");
	td1.appendChild(text);
	tr.appendChild(td1);
	tr.appendChild(td2);
	document.getElementById('tbl').appendChild(tr);
	count++;
}

function removeRow(argument) {
	count--;
	var tr = document.getElementById("other" + count);
	document.getElementById('tbl').removeChild(tr);

}
function showPosition(e) {
	var txt = document.getElementById('threeone');
	txt.innerHTML = e.clientX + ',' + e.clientY;
}

function showTB(argument) {
	window.open("https://www.taobao.com");
}