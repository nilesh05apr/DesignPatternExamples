const logger = require('../logger/logger');
const properties = require('../package.json');

let about = {
    about: (req,res) => {
        if(req.method == 'GET') {
            let aboutInfo = {
                name: properties.name,
                description: properties.description,
                author: properties.author                
            }
            let date = new Date();
            logger.logCount()
            logger.log(`${date} : about service called.`)
            logger.logCount()
            res.status(200).json(aboutInfo)
        } else {
            res.status(400)
        }
    }
}

module.exports = about;