\name{nutrigenomic}
\docType{data}
\alias{nutrigenomic}
\title{Nutrigenomic Study}

\description{
  Study the effects of five diet treatments on 21 liver lipids and 120
  hepatic gene expression in wild-type and PPAR-alpha deficient mice.  We
  use a multivariate mixed random forest analysis by regressing gene
  expression, diet and genotype (the x-variables) on lipid expressions
  (the multivariate y-responses).
}
\references{
  Martin P.G. et al. (2007). Novel aspects of PPAR-alpha-mediated
  regulation of lipid and xenobiotic metabolism revealed through a
  nutrigenomic study. \emph{Hepatology}, 45(3), 767--777.
}
\examples{
\donttest{
## ------------------------------------------------------------
## multivariate regression forests using Mahalanobis splitting
## lipids (all real values) used as the multivariate y
## ------------------------------------------------------------

## load the data
data(nutrigenomic, package = "randomForestSRC")

## parse into y and x data
ydta <- nutrigenomic$lipids
xdta <- data.frame(nutrigenomic$genes,
                   diet = nutrigenomic$diet,
                   genotype = nutrigenomic$genotype)

## multivariate mixed forest call
obj <- rfsrc(get.mv.formula(colnames(ydta)),
             data.frame(ydta, xdta),
             importance=TRUE, nsplit = 10, splitrule = "mahalanobis")

## ------------------------------------------------------------
## plot the standarized performance and VIMP values
## ------------------------------------------------------------

## acquire the error rate for each of the 21-coordinates 
## standardize to allow for comparison across coordinates
serr <- get.mv.error(obj, standardize = TRUE)

## acquire standardized VIMP 
svimp <- get.mv.vimp(obj, standardize = TRUE)

par(mfrow = c(1,2))
plot(serr, xlab = "Lipids", ylab = "Standardized Performance")
matplot(svimp, xlab = "Genes/Diet/Genotype", ylab = "Standardized VIMP")


## ------------------------------------------------------------
## plot some trees
## ------------------------------------------------------------

plot(get.tree(obj, 1))
plot(get.tree(obj, 2))
plot(get.tree(obj, 3))


## ------------------------------------------------------------
## Compare above to default composite (independent) splitting
## ------------------------------------------------------------

obj2 <- rfsrc(get.mv.formula(colnames(ydta)),
              data.frame(ydta, xdta),
              importance=TRUE, nsplit = 10)

imp <- data.frame(mahalanobis = rowMeans(get.mv.vimp(obj,  standardize = TRUE)),
                  default     = rowMeans(get.mv.vimp(obj2, standardize = TRUE)))

print(imp[order(imp["mahalanobis"]), ])



}}
\keyword{datasets}
