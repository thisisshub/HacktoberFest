const router = require('express').Router()
const controller=require('./controller')

router.get('/',controller.world_stats)

router.get('/total_ratio',controller.total_world_ratio)

router.get('/:country',controller.country_stat)

router.get('/:country/history',controller.country_stat_history)

module.exports=router