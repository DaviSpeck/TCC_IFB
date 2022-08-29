let exec = require('child_process').execFile;

let express = require('express');
let router = express.Router();
let fs = require('fs'), readline = require('readline');
const app = express();
const formidable = require('formidable');

const moreOneLine = require('fs').promises


let fun = function (){
    return new Promise((resolve,reject)=>{
        exec('RI.exe', function(err, data) { 
            resolve(data);                     
        });  
    });
}

let fun_input = function (texto, file){

    fs.rename('C:/Users/user/Desktop/Obras/'+file, './texto.pdf', function(err){
        if(err) throw err;	
    });

    fs.writeFile("input.txt", texto, function(erro) {
        if(erro) throw erro;
    });

    moreOneLine.appendFile("input.txt", "\n"+"texto.pdf", (erro) => {
        if (erro) throw erro;
    });

}

let fun_ranking = function (){
   return fs.readFileSync('ranking.txt', 'utf8').toString().split("\n");
}
 
router.get('/', function(req, res) {
    const form = new formidable.IncomingForm();
    form.parse(req, (err, fields, files) => {
    });
    res.sendFile(__dirname + '/templates/index.html');
});

router.get('/rank', function(req, res) {
    res.sendFile(__dirname + '/templates/rank.html');
});

router.get('/ranking/:texto/:file', async function(req, res) {

    const texto = req.params.texto
    const file = req.params.file

    await fun_input(texto, file);

    await fun();

    let arrayRank = await fun_ranking();
    console.log(arrayRank);
    res.json(arrayRank)
});

router.get('/aparicoes/:id', function(req, res) {

    const id = req.params.id;

    let arrayAparicoes = fs.readFileSync('aparicoes.txt').toString().split("\n");
    let arrayRes = [];
    for(i in arrayAparicoes) {
        id_array = arrayAparicoes[i].replace(/[^0-9]/g,'')
        if (id == id_array){
            arrayRes.push(arrayAparicoes[i])
        }
    }

    res.json(arrayRes);
});

router.get('/aparicoes', function(req, res) {
    res.sendFile(__dirname + '/templates/aparicoes.html');
});

app.use(express.json());
app.use(express.urlencoded({ extended: true }));



module.exports = router;