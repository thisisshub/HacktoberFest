const fetch=require('node-fetch')

module.exports={
    total_world_ratio:async(req,res,next)=>{
        let url='https://coronavirus-monitor.p.rapidapi.com/coronavirus/worldstat.php'
        console.log(url)
        try {
            const response=await fetch(url,{
                            headers: {
                                        "x-rapidapi-host": "coronavirus-monitor.p.rapidapi.com",
                                        "x-rapidapi-key": process.env.API_KEY
                                    },
                            })
            console.log(response)                
            const responseData=await response.json()
            res.status("200").json({
                data: responseData
            })
    
        } catch (error) {
            res.status('400').json({
                status:400,
                error:error
            })
        }
    },
    world_stats:async(req,res,next)=>{
        let url='https://coronavirus-monitor.p.rapidapi.com/coronavirus/cases_by_country.php'
        console.log(url)
        try {
            const response=await fetch(url,{
                            headers: {
                                        "x-rapidapi-host": "coronavirus-monitor.p.rapidapi.com",
                                        "x-rapidapi-key": process.env.API_KEY
                                    },
                            })        
            const responseData=await response.json()
            res.status("200").json({
                data: responseData.countries_stat
            })
    
        } catch (error) {
            res.status('400').json({
                status:400,
                error:error
            })
        }
    },
    country_stat:async(req,res,next)=>{
        const country= req.params.country
        let url='https://coronavirus-monitor.p.rapidapi.com/coronavirus/latest_stat_by_country.php?country='+country
        console.log(url)
        try {
            const response=await fetch(url,{
                            headers: {
                                        "x-rapidapi-host": "coronavirus-monitor.p.rapidapi.com",
                                        "x-rapidapi-key": process.env.API_KEY
                                    },
                            })        
            const responseData=await response.json()
            res.status("200").json({
                data: responseData.latest_stat_by_country
            })
    
        } catch (error) {
            res.status('400').json({
                status:400,
                error:error
            })
        }
    },
    country_stat_history:async(req,res,next)=>{
        const country= req.params.country
        let url='https://coronavirus-monitor.p.rapidapi.com/coronavirus/cases_by_particular_country.php?country='+country
        console.log(url)
        try {
            const response=await fetch(url,{
                            headers: {
                                        "x-rapidapi-host": "coronavirus-monitor.p.rapidapi.com",
                                        "x-rapidapi-key": process.env.API_KEY
                                    },
                            })        
            const responseData=await response.json()
            res.status("200").json({
                data: responseData.stat_by_country
            })
    
        } catch (error) {
            res.status('400').json({
                status:400,
                error:error
            })
        }
    }
}
