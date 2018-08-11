//index.js implemented with help from Web Development with Node and Express textbook

var express = require('express');
var app = express();

// set up handlebars view engine
var handlebars = require('express3-handlebars')
    .create({ defaultLayout:'main' });
app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');

//set port
app.set('port', process.env.PORT || 3000);

app.use(express.static(__dirname + '/public'));

//web pages
app.get('/home', function(req, res) {
	res.render('home');
});
app.get('/about', function(req,res){
	res.render('about');
});

app.get('/hobbies', function(req, res){
	res.render('hobbies');
});

app.get('/resume', function(req, res){
	res.render('resume');
});
    
// 404 catch-all handler (middleware)
app.use(function(req, res, next){
	res.status(404);
	res.render('404');
});

// 500 error handler (middleware)
app.use(function(err, req, res, next){
	console.error(err.stack);
	res.status(500);
	res.render('500');
});

app.listen(app.get('port'), function(){
  console.log( 'https://git.heroku.com/devingendron-website.git' + 
    app.get('port') + '; press Ctrl-C to terminate.' );
});