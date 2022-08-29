const express = require("express");
const app = express();

app.use('/public', express.static('public'));

var exec = require('child_process').execFile;
 
let userRoute = require('./route');
app.use('/', userRoute);
 
app.listen(3000, ()=>{
    console.log('Funciona');
})