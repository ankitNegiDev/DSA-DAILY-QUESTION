function defangingIp(str){
    let newStr="";
    for(let i=0; i<str.length; i++){
        if(str[i]==="."){
            newStr=newStr+"[]";
        }else{
            newStr=newStr+str[i];
        }
    }
    return newStr;
}
console.log(defangingIp("123.345.45.01"));


// we can alos use replace.all () methode .. als0