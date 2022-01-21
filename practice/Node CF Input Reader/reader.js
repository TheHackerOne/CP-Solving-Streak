const fs = require('fs')
const app = require('express')()
const bodyParser = require( "body-parser")

const port = 12345;
app.use(bodyParser.json());

app.post("/", (req, res) => {
	const data = req.body;
	tests = []
	for(test of data["tests"]){
		tests.push({
		"test" :test["input"],
		"correct_answers": [test[ "output"].trim()]
		})
	}
	console.log(tests)
	fs.writeFile('C:\\Users\\hp\\Desktop\\CP-Solving-Streak\\practice\\practice.cpp__tests', JSON.stringify(tests), function(){
		console.log('File Written Successfully')
	})
	console.log("Loaded1");
	res.sendStatus (200);
});

app.listen(port, err => {
	if (err) {
		console.error (err) ;
		process.exit (1) ;
	}
	console.log(`Listening on port ${port}`);
});

