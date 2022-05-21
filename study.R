f_size = 0.01
cex_size = 0.5
pch_id = 20
columns = c("tour", "score1", "score2")

# 2 courbes du score de chaque joueur selon le tour
plot_score_joueurs <- function(name)
{
	data = read.table(name)
    colnames(data) = columns

    plot(data$tour,
        data$score1,
        pch = pch_id,
        cex = cex_size,
        xlab = "N° du tour",
        ylab = "Score",
        col = "blue",
        main = "Score en fonction du numéro de tour")
    lines(lowess(data$tour, data$score1, f = f_size), col = "blue")
    points(data$tour, data$score2, pch = pch_id, cex = cex_size, col = "red")
    lines(lowess(data$tour, data$score2, f = f_size), col = "red")

    legend("bottomright", legend = paste("Joueur", c("1", "2")),
    lty = "solid", col = c("blue", "red"))
}

plot_score_joueurs("tours.data")