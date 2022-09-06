const express = require('express');
const app = express();

const routes = require('./routes/routes');
routes(app)

const port = 8000 | process.env.PORT;

app.listen(port, ()=> {
    console.log(`running on: http://localhost:${port}`)
});