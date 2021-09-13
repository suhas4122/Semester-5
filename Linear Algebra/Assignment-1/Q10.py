import wikipedia
import pandas as pd
import nltk
import string
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
from sklearn.manifold import MDS
nltk.download('punkt')

#selective wikipedia article topics
articles = ['Shah_Rukh_Khan', 'Leonardo_DiCaprio', 'Will_Smith',
            'Kamal_Haasan', 'Tom_Cruise', 'Dwayne_Johnson', 'Brad_Pitt',
            'Johnny_Depp', 'Morgan_Freeman', 'Ed_Sheeran', 'A._R._Rahman',
            'Bruno_Mars', 'Taylor_Swift', 'Eminem', 'Shakira', 'Ellie_Goulding',
            'Michael_Jackson', 'Selena_Gomez', 'Ilaiyaraaja', 'Lionel_Messi',
            'Cristiano_Ronaldo', 'Tiger_Woods', 'Rafael_Nadal', 'Usain_Bolt',
            'Stephen_Curry', 'Roger_Federer', 'Virat_Kohli', 'Serena_Williams',
            'MS_Dhoni', 'James_Patterson', 'Stephen_King', 'J._K._Rowling',
            'Dan_Brown', 'Agatha_Christie', 'Ken_Follett', 'Neil_Gaiman', 
            'John_Grisham', 'Nora_Roberts', 'Arundhati_Roy', 'Mark_Zuckerberg',
            'Jeff_Bezos', 'Bill_Gates', 'Larry_Page', 'Jack_Ma', 'Tim_Cook', 
            'Elon_Musk', 'Warren_Buffett', 'Akio_Toyoda', 'Mukesh_Ambani',
            'Imran_Khan', 'Xi_Jinping', 'Vladimir_Putin', 'Donald_Trump', 
            'Barack_Obama', 'David_Cameron', 'Narendra_Modi', 'Hillary_Clinton',
            'Bill_Clinton', 'Rahul_Gandhi']

#obtaining the summary of each article
article_summaries = {}

for i in articles:
    article_summaries.update({i : wikipedia.summary(i, auto_suggest=False)})
     
#exploring the entry of president obama
article_summaries['Barack_Obama']  

#converting the above dictionary to a dataframe
corpus = pd.DataFrame.from_dict(article_summaries, orient = 'index',
                                columns = ['Summary'])   
#resetting the index
corpus.reset_index(level=0, inplace=True)

#renaming the column name
corpus = corpus.rename(columns = {'index' : 'Article_Name'})

#tokenizing summary
#converting the summary to complete lowercase
corpus['Terms'] = [x.lower() for x in corpus.Summary]

#removing punctuations from the list of terms
corpus['Terms'] = [''.join(c for c in s if c not in string.punctuation) for s in corpus.Terms]

#finally tokenizing
corpus['Terms'] = corpus.apply(lambda row: nltk.word_tokenize(row['Terms']),
                               axis=1)

#obtaining tf-idf 
tfidf_vectorizer = TfidfVectorizer(stop_words='english')
tfidf_matrix = tfidf_vectorizer.fit_transform(corpus.Summary)
print(tfidf_matrix.shape)

#finding cosine similarities among summaries
# dist = 1 - cosine_similarity(tfidf_matrix)
# dist

#modelling
#k-means clustering
num_clusters = 6
km = KMeans(n_clusters=num_clusters)
km.fit(tfidf_matrix)
clusters = km.labels_.tolist()

#creating a dictionary with obtained clusters
articles = {'title': corpus.Article_Name, 'summary': corpus.Summary, 'cluster': clusters}

#transforming the above dictionary to a dataframe
article_df = pd.DataFrame.from_dict(articles)
article_df = article_df.drop(['summary'], axis = 1)

#finding no. of articles per cluster
article_df['cluster'].value_counts()

#identifying the main topics of each cluster
print("Top terms per cluster:")
order_centroids = km.cluster_centers_.argsort()[:, ::-1]
terms = tfidf_vectorizer.get_feature_names()
for i in range(num_clusters):
    print("Cluster %d:" % i),
    for ind in order_centroids[i, :10]:
        print(' %s' % terms[ind]),

#multidimensional scaling for converting dist matrix to 2D array
MDS()
mds = MDS(n_components=2, dissimilarity="precomputed", random_state=1)
pos = mds.fit_transform(dist)  # shape (n_components, n_samples)
xs, ys = pos[:, 0], pos[:, 1]

#visualizing clusters
#setting up colors per clusters using a dict
cluster_colors = {0: '#1b9e77', 1: '#d95f02', 2: '#7570b3', 3: '#e7298a', 4: '#66a61e', 5: '#FFB139', 6: '#39C8C6'}

#setting up cluster names using a dict
cluster_names = {0: 'President, party, election', 
                 1: 'Titles, world, player', 
                 2: 'Album, music, number', 
                 3: 'Actor, film, drama', 
                 4: 'Books, novels, copies',
                 5: 'Business, founder, executive'}

#creating data frame that has the result of the MDS plus the cluster numbers and titles
article_df['x'] = xs[article_df.index]
article_df['y'] = ys[article_df.index]

#grouping the dataframe by cluster
grouped_df = article_df.groupby(['cluster'])

for key, item in grouped_df:
    print(grouped_df.get_group(key), "\n\n")

# setting up the plot
fig, ax = plt.subplots(figsize=(17, 9)) # set size
ax.margins(0.05) 

#iterating through groups to layer the plot
#using the cluster_name and cluster_color dicts with the 'name' lookup to return the appropriate color/label
for name, group in grouped_df:
    ax.plot(group.x, group.y, marker='o', linestyle='', ms=12, 
            label=cluster_names[name], color=cluster_colors[name], 
            mec='none')
    ax.set_aspect('auto')
    ax.tick_params(\
        axis= 'x',         
        which='both',      
        bottom=False,      
        top=False,         
        labelbottom=False)
    ax.tick_params(\
        axis= 'y',         
        which='both',      
        left=False,      
        top=False,        
        labelleft=False)
    
ax.legend(numpoints=1)  

#adding label in x,y position with the label as the article_df title
for i in range(len(article_df)):
    ax.text(article_df.loc[i]['x'], article_df.loc[i]['y'], article_df.loc[i]['title'], size=8)  
     
plt.show()


#for final interpretation
article_df['cluster'].value_counts()            

new_df = article_df.drop(['x','y'], axis = 1)
new_df = new_df.set_index('title')
new_grp = new_df.groupby('cluster')
new_grp.groups
for name,group in new_grp:
    print(name)
    print(group)