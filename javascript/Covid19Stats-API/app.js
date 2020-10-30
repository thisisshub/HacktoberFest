const express=require('express');
const app = express()
const bodyParser=require('body-parser');
const cors=require('cors');
const dotenv=require('dotenv');


dotenv.config()
// Parsing Body
app.use(bodyParser.urlencoded({ extended: false }))
app.use(bodyParser.json())
app.use(cors())


const router=require('./covid_router')

// Set url
app.use('/',router)

// Error Handling
app.use((req, res, next) => {
    const error = new Error('Undefined Route')
    error.status = 404
    next(error)
})
app.use((error, req, res, next) => {
    res.status(error.status || 459)
    res.json({
        Error: {
            message: error.message
        }
    })
})

const port=process.env.PORT || 8000

app.listen(port)

