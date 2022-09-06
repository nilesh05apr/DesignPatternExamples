const logger = require('../logger/logger');

let health = {
    health: (req,res) => {
        if(req.method == 'GET') {
            let date = new Date();
            logger.logCount()
            logger.log(`${date} : health service called.`)
            logger.logCount()
            res.status(200).json({"status":"ok"})
        } else {
            res.status(400)
        }
    }
}

module.exports = health;