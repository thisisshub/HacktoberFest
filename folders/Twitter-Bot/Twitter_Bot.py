import tweepy
import time

auth = tweepy.OAuthHandler(consumer_key,consumer_secret)
auth.set_access_token(access_token, access_token_secret)

api = tweepy.API(auth, wait_on_rate_limit=True, wait_on_rate_limit_notify=True)

for follower in tweepy.Cursor(api.followers).items():
    follower.follow()

#Add more tags you want to retweet
search = '#100daysofcode'
nrTweets = 100

for tweet in tweepy.Cursor(api.search, search).items(nrTweets):
    try:
        print('\nTweet by: @' + tweet.user.screen_name)
        
        tweet.favorite()
        print('Liked the tweet')
        tweet.retweet()
        print('Retweeted tweet')
        if not tweet.user.following: 
                tweet.user.follow() 
                print('Followed the user')
                
        time.sleep(100)
    except tweepy.TweepError as e:
        print(e.reason)
    except StopIteration:
        break
