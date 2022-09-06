const logger = require('../logger/logger');

let logdata = {
    logdata: (req,res) => {
        if(req.method == 'GET') {
            res.status(200).json({"logdata":logger.logs})
        } else {
            res.status(400)
        }
    }
}

module.exports = logdata;